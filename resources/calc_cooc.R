library(raster)
library(sp)
library(sf)
library(dplyr)
require(rstudioapi) #use to automatically set working directory

##########################################
#set working directory to a directory containing script
tryCatch(setwd(getSrcDirectory()[1]), error=function(e) setwd(dirname(rstudioapi::getActiveDocumentContext()$path)))


##############
#census_sp contain 4 "layers" for Cook County
###cat - there is categorical raster with 5 classess (representing race categories 1- asian, 2-black, 3-hisp, 4-other, 5-white), use to identify pairs of categories in cooc matrix
###weights - there is numerical raster with weights used to calculate modified cooc matrix
###cns_units, cns_id - block ids - there are not used in this script
census_sp = readRDS("data/sp_weights_adj_2010.rds")

#shapefile use to crop raster
region =st_read("data/c29_r30_60_60.shp", stringsAsFactors=FALSE)

#prefix for results file
fname = "c29_r30_60_adj_2010"

rcat = 1:5 # vector of categories assign to race

#create raster stack based on census sp
rast = stack(census_sp)

#remove census sp - calculation are based on raster object provided by raster package
rm(census_sp)

#crop input raster to shapefile region
rst = crop(rast, region)
rstm <- mask(rst, region)

#r is a raster with categories
r = rstm[["cat"]]

#rw is raster with weights
rw = rstm[["weights"]]

clr = c("#f17160", "#6ebe44","#7e69af", "#c27515","#f8df1d") #colors for race categories
plot(r, col=clr)
plot(rw)
##########################


# r = x
# rw = w
# rcat = 1:3
#Create unique combination of race categories

#unique combination
un = expand.grid(rcat, rcat)
un$ord = as.integer(row.names(un))
#un
#unique combination, order doesnt matter
sort_un = as.data.frame(t(apply(un[,1:2], 1, sort)))
sort_un$ord = as.integer(row.names(sort_un))
#sort_un
un2 = unique(sort_un[,1:2])
un2$gr = 1:nrow(un2)
sort_un2 = merge(sort_un, un2, by=c("V1", "V2"))

#This data frame contain category for focus cell, neighboor cell and group (gr).
uniq = merge(un, sort_un2[, c("ord", "gr")], by="ord")
colnames(uniq) = c("ord", "focus_cell", "neigh_cell", "gr")
uniq$ord <- NULL
#uniq


ptm <- proc.time()
#result is a data frame with each pair focus-neigh cell
result = data.frame()
for (i in 1:nrow(r)) {
  for (j in 1:ncol(r)) {
    #focus cell contain category for focus cell
    focus_cell = r[i, j]
    #neigh_cell is the vector wiht categories for four neighboorhood cell
    neigh_cell = c(r[i, j-1], r[i, j+1], r[i-1, j], r[i+1, j])
    #w_focus cell contain weight value for focus cell
    w_focus_cell = rw[i, j]
    #neigh_cell is the vector wiht weights value for four neighboorhood cell
    w_neigh_cell = c(rw[i, j-1], rw[i, j+1], rw[i-1, j], rw[i+1, j])
    #res is a data frame with for rows - each row is related to one pair focus-neighboor cell
    res = as.data.frame(cbind(focus_cell , neigh_cell, w_focus_cell, w_neigh_cell, i, j))
    #print(res)
    #calculate value based on weights. In this example there is a mean. FUN can be any user-defined function
    res$fnc = apply(res[, c("w_focus_cell", "w_neigh_cell")], 1, FUN=mean)
    #res$fnc = w_focus_cell
    result = rbind(result, res)
}#end ncol loop
}#end nrow loop


#merge data frame result and uniq (contain 3 cols category of focus cell, neig cell and gr)
result_df = merge(result, uniq, by = c("focus_cell", "neigh_cell"))
# saveRDS(result_df, paste(fname, "_result_df.rds", sep=""))

#just for check
table(result_df$gr)

head(result_df)

#Summarize result df by group
#symetric matrix

by_gr = group_by(result_df, by=gr)

smr = summarize(by_gr, n=n(), suma = sum(fnc))

out_df = merge(smr, un2, by.x="by", by.y="gr", all.y=TRUE)
colnames(out_df) = c("gr", "n", "suma", "focuc_cell", "neigh_cell")


out_df[is.na(out_df)] <- 0
out_df


saveRDS(out_df, paste(fname, "_out_df.rds", sep=""))
proc.time() - ptm



#display coocurence matrix based on out_df

make_mat <- function(x) {
  x1=x[1:5]
  x2=c(0, x[6:9])
  x3=c(0, 0, x[10:12])
  x4=c(0,0, 0, x[13:14])
  x5=c(0, 0, 0, 0, x[15])
  m = rbind(x1,x2,x3,x4,x5)
  m[upper.tri(m,diag=FALSE)] <- m[upper.tri(m,diag=FALSE)]/2 #upper part without diagonal need to be divided by 2. #dodalam unlist jak nie zadziala
  m[lower.tri(m)] <- t(m)[lower.tri(m)] #copy value from upper part to lower part
  return(m)
}

#calculation for cell, there is a standard coocurence matrix based on categories
mc = make_mat(out_df$n)
mc
#there is coocurence matrix based on weights
mp = make_mat(out_df$suma)
mp

# rcpp_get_coocurrence_matrix(as.matrix(r), as.matrix(4))
# rcpp_get_wecoma(as.matrix(r), as.matrix(rw), matrix(4))
