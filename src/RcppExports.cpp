// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "../inst/include/comat.h"
#include <RcppArmadillo.h>
#include <Rcpp.h>
#include <string>
#include <set>

using namespace Rcpp;

// create_attributes
List create_attributes(List x);
RcppExport SEXP _comat_create_attributes(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(create_attributes(x));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_xy_from_matrix
IntegerMatrix rcpp_xy_from_matrix(arma::imat x, Rcpp::Nullable<Rcpp::IntegerVector> cell);
RcppExport SEXP _comat_rcpp_xy_from_matrix(SEXP xSEXP, SEXP cellSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::imat >::type x(xSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::IntegerVector> >::type cell(cellSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_xy_from_matrix(x, cell));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_cell_from_xy
IntegerVector rcpp_cell_from_xy(arma::imat x, IntegerMatrix y);
RcppExport SEXP _comat_rcpp_cell_from_xy(SEXP xSEXP, SEXP ySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::imat >::type x(xSEXP);
    Rcpp::traits::input_parameter< IntegerMatrix >::type y(ySEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_cell_from_xy(x, y));
    return rcpp_result_gen;
END_RCPP
}
// create_neighborhood
IntegerMatrix create_neighborhood(arma::imat directions);
RcppExport SEXP _comat_create_neighborhood(SEXP directionsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::imat >::type directions(directionsSEXP);
    rcpp_result_gen = Rcpp::wrap(create_neighborhood(directions));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_get_entropy
double rcpp_get_entropy(NumericVector x, std::string base);
static SEXP _comat_rcpp_get_entropy_try(SEXP xSEXP, SEXP baseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< std::string >::type base(baseSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_get_entropy(x, base));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _comat_rcpp_get_entropy(SEXP xSEXP, SEXP baseSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_comat_rcpp_get_entropy_try(xSEXP, baseSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// get_motifel_size
int get_motifel_size(int num_r, int num_c, int shift);
static SEXP _comat_get_motifel_size_try(SEXP num_rSEXP, SEXP num_cSEXP, SEXP shiftSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< int >::type num_r(num_rSEXP);
    Rcpp::traits::input_parameter< int >::type num_c(num_cSEXP);
    Rcpp::traits::input_parameter< int >::type shift(shiftSEXP);
    rcpp_result_gen = Rcpp::wrap(get_motifel_size(num_r, num_c, shift));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _comat_get_motifel_size(SEXP num_rSEXP, SEXP num_cSEXP, SEXP shiftSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_comat_get_motifel_size_try(num_rSEXP, num_cSEXP, shiftSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// get_motifels_coma
List get_motifels_coma(IntegerMatrix x, const arma::imat directions, int size, int shift, const std::string fun, const std::string na_action);
static SEXP _comat_get_motifels_coma_try(SEXP xSEXP, SEXP directionsSEXP, SEXP sizeSEXP, SEXP shiftSEXP, SEXP funSEXP, SEXP na_actionSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< IntegerMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< const arma::imat >::type directions(directionsSEXP);
    Rcpp::traits::input_parameter< int >::type size(sizeSEXP);
    Rcpp::traits::input_parameter< int >::type shift(shiftSEXP);
    Rcpp::traits::input_parameter< const std::string >::type fun(funSEXP);
    Rcpp::traits::input_parameter< const std::string >::type na_action(na_actionSEXP);
    rcpp_result_gen = Rcpp::wrap(get_motifels_coma(x, directions, size, shift, fun, na_action));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _comat_get_motifels_coma(SEXP xSEXP, SEXP directionsSEXP, SEXP sizeSEXP, SEXP shiftSEXP, SEXP funSEXP, SEXP na_actionSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_comat_get_motifels_coma_try(xSEXP, directionsSEXP, sizeSEXP, shiftSEXP, funSEXP, na_actionSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// get_motifels_wecoma
List get_motifels_wecoma(IntegerMatrix x, NumericMatrix w, const arma::imat directions, int size, int shift, const std::string fun, const std::string na_action);
static SEXP _comat_get_motifels_wecoma_try(SEXP xSEXP, SEXP wSEXP, SEXP directionsSEXP, SEXP sizeSEXP, SEXP shiftSEXP, SEXP funSEXP, SEXP na_actionSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< IntegerMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type w(wSEXP);
    Rcpp::traits::input_parameter< const arma::imat >::type directions(directionsSEXP);
    Rcpp::traits::input_parameter< int >::type size(sizeSEXP);
    Rcpp::traits::input_parameter< int >::type shift(shiftSEXP);
    Rcpp::traits::input_parameter< const std::string >::type fun(funSEXP);
    Rcpp::traits::input_parameter< const std::string >::type na_action(na_actionSEXP);
    rcpp_result_gen = Rcpp::wrap(get_motifels_wecoma(x, w, directions, size, shift, fun, na_action));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _comat_get_motifels_wecoma(SEXP xSEXP, SEXP wSEXP, SEXP directionsSEXP, SEXP sizeSEXP, SEXP shiftSEXP, SEXP funSEXP, SEXP na_actionSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_comat_get_motifels_wecoma_try(xSEXP, wSEXP, directionsSEXP, sizeSEXP, shiftSEXP, funSEXP, na_actionSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// get_motifels_cocoma
List get_motifels_cocoma(IntegerMatrix x, IntegerMatrix y, const arma::imat directions, int size, int shift);
static SEXP _comat_get_motifels_cocoma_try(SEXP xSEXP, SEXP ySEXP, SEXP directionsSEXP, SEXP sizeSEXP, SEXP shiftSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< IntegerMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< IntegerMatrix >::type y(ySEXP);
    Rcpp::traits::input_parameter< const arma::imat >::type directions(directionsSEXP);
    Rcpp::traits::input_parameter< int >::type size(sizeSEXP);
    Rcpp::traits::input_parameter< int >::type shift(shiftSEXP);
    rcpp_result_gen = Rcpp::wrap(get_motifels_cocoma(x, y, directions, size, shift));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _comat_get_motifels_cocoma(SEXP xSEXP, SEXP ySEXP, SEXP directionsSEXP, SEXP sizeSEXP, SEXP shiftSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_comat_get_motifels_cocoma_try(xSEXP, ySEXP, directionsSEXP, sizeSEXP, shiftSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// get_motifels_incoma
List get_motifels_incoma(const List input, const arma::imat directions, int size, int shift, const std::string fun, const std::string na_action);
static SEXP _comat_get_motifels_incoma_try(SEXP inputSEXP, SEXP directionsSEXP, SEXP sizeSEXP, SEXP shiftSEXP, SEXP funSEXP, SEXP na_actionSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const List >::type input(inputSEXP);
    Rcpp::traits::input_parameter< const arma::imat >::type directions(directionsSEXP);
    Rcpp::traits::input_parameter< int >::type size(sizeSEXP);
    Rcpp::traits::input_parameter< int >::type shift(shiftSEXP);
    Rcpp::traits::input_parameter< const std::string >::type fun(funSEXP);
    Rcpp::traits::input_parameter< const std::string >::type na_action(na_actionSEXP);
    rcpp_result_gen = Rcpp::wrap(get_motifels_incoma(input, directions, size, shift, fun, na_action));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _comat_get_motifels_incoma(SEXP inputSEXP, SEXP directionsSEXP, SEXP sizeSEXP, SEXP shiftSEXP, SEXP funSEXP, SEXP na_actionSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_comat_get_motifels_incoma_try(inputSEXP, directionsSEXP, sizeSEXP, shiftSEXP, funSEXP, na_actionSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// get_unique_values
std::vector<int> get_unique_values(const Rcpp::IntegerVector& x, bool na_omit);
static SEXP _comat_get_unique_values_try(SEXP xSEXP, SEXP na_omitSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const Rcpp::IntegerVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< bool >::type na_omit(na_omitSEXP);
    rcpp_result_gen = Rcpp::wrap(get_unique_values(x, na_omit));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _comat_get_unique_values(SEXP xSEXP, SEXP na_omitSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_comat_get_unique_values_try(xSEXP, na_omitSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// rcpp_get_cocoma
IntegerMatrix rcpp_get_cocoma(const IntegerMatrix x, const IntegerMatrix y, const arma::imat directions);
static SEXP _comat_rcpp_get_cocoma_try(SEXP xSEXP, SEXP ySEXP, SEXP directionsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const IntegerMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< const IntegerMatrix >::type y(ySEXP);
    Rcpp::traits::input_parameter< const arma::imat >::type directions(directionsSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_get_cocoma(x, y, directions));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _comat_rcpp_get_cocoma(SEXP xSEXP, SEXP ySEXP, SEXP directionsSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_comat_rcpp_get_cocoma_try(xSEXP, ySEXP, directionsSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// rcpp_get_cocoma_internal
IntegerMatrix rcpp_get_cocoma_internal(const IntegerMatrix x, const IntegerMatrix y, const arma::imat directions, std::vector<int> classes_x, std::vector<int> classes_y);
static SEXP _comat_rcpp_get_cocoma_internal_try(SEXP xSEXP, SEXP ySEXP, SEXP directionsSEXP, SEXP classes_xSEXP, SEXP classes_ySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const IntegerMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< const IntegerMatrix >::type y(ySEXP);
    Rcpp::traits::input_parameter< const arma::imat >::type directions(directionsSEXP);
    Rcpp::traits::input_parameter< std::vector<int> >::type classes_x(classes_xSEXP);
    Rcpp::traits::input_parameter< std::vector<int> >::type classes_y(classes_ySEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_get_cocoma_internal(x, y, directions, classes_x, classes_y));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _comat_rcpp_get_cocoma_internal(SEXP xSEXP, SEXP ySEXP, SEXP directionsSEXP, SEXP classes_xSEXP, SEXP classes_ySEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_comat_rcpp_get_cocoma_internal_try(xSEXP, ySEXP, directionsSEXP, classes_xSEXP, classes_ySEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// rcpp_get_coma
IntegerMatrix rcpp_get_coma(const IntegerMatrix x, const arma::imat directions);
static SEXP _comat_rcpp_get_coma_try(SEXP xSEXP, SEXP directionsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const IntegerMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< const arma::imat >::type directions(directionsSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_get_coma(x, directions));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _comat_rcpp_get_coma(SEXP xSEXP, SEXP directionsSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_comat_rcpp_get_coma_try(xSEXP, directionsSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// rcpp_get_coma_internal
IntegerMatrix rcpp_get_coma_internal(const IntegerMatrix x, const arma::imat directions, std::vector<int> classes);
static SEXP _comat_rcpp_get_coma_internal_try(SEXP xSEXP, SEXP directionsSEXP, SEXP classesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const IntegerMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< const arma::imat >::type directions(directionsSEXP);
    Rcpp::traits::input_parameter< std::vector<int> >::type classes(classesSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_get_coma_internal(x, directions, classes));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _comat_rcpp_get_coma_internal(SEXP xSEXP, SEXP directionsSEXP, SEXP classesSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_comat_rcpp_get_coma_internal_try(xSEXP, directionsSEXP, classesSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// rcpp_get_incoma
IntegerMatrix rcpp_get_incoma(const List x, const arma::imat directions);
static SEXP _comat_rcpp_get_incoma_try(SEXP xSEXP, SEXP directionsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const List >::type x(xSEXP);
    Rcpp::traits::input_parameter< const arma::imat >::type directions(directionsSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_get_incoma(x, directions));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _comat_rcpp_get_incoma(SEXP xSEXP, SEXP directionsSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_comat_rcpp_get_incoma_try(xSEXP, directionsSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// rcpp_get_incoma_internal
IntegerMatrix rcpp_get_incoma_internal(const List x, const arma::imat directions, List classes);
static SEXP _comat_rcpp_get_incoma_internal_try(SEXP xSEXP, SEXP directionsSEXP, SEXP classesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const List >::type x(xSEXP);
    Rcpp::traits::input_parameter< const arma::imat >::type directions(directionsSEXP);
    Rcpp::traits::input_parameter< List >::type classes(classesSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_get_incoma_internal(x, directions, classes));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _comat_rcpp_get_incoma_internal(SEXP xSEXP, SEXP directionsSEXP, SEXP classesSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_comat_rcpp_get_incoma_internal_try(xSEXP, directionsSEXP, classesSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// rcpp_get_vec
NumericVector rcpp_get_vec(NumericMatrix x, bool ordered);
static SEXP _comat_rcpp_get_vec_try(SEXP xSEXP, SEXP orderedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< bool >::type ordered(orderedSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_get_vec(x, ordered));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _comat_rcpp_get_vec(SEXP xSEXP, SEXP orderedSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_comat_rcpp_get_vec_try(xSEXP, orderedSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// rcpp_get_wecove
NumericVector rcpp_get_wecove(NumericMatrix x, bool ordered);
static SEXP _comat_rcpp_get_wecove_try(SEXP xSEXP, SEXP orderedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< bool >::type ordered(orderedSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_get_wecove(x, ordered));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _comat_rcpp_get_wecove(SEXP xSEXP, SEXP orderedSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_comat_rcpp_get_wecove_try(xSEXP, orderedSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// rcpp_get_wecoma
NumericMatrix rcpp_get_wecoma(const IntegerMatrix x, const NumericMatrix w, const arma::imat directions, const std::string fun, const std::string na_action);
static SEXP _comat_rcpp_get_wecoma_try(SEXP xSEXP, SEXP wSEXP, SEXP directionsSEXP, SEXP funSEXP, SEXP na_actionSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const IntegerMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< const NumericMatrix >::type w(wSEXP);
    Rcpp::traits::input_parameter< const arma::imat >::type directions(directionsSEXP);
    Rcpp::traits::input_parameter< const std::string >::type fun(funSEXP);
    Rcpp::traits::input_parameter< const std::string >::type na_action(na_actionSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_get_wecoma(x, w, directions, fun, na_action));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _comat_rcpp_get_wecoma(SEXP xSEXP, SEXP wSEXP, SEXP directionsSEXP, SEXP funSEXP, SEXP na_actionSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_comat_rcpp_get_wecoma_try(xSEXP, wSEXP, directionsSEXP, funSEXP, na_actionSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// rcpp_get_wecoma_internal
NumericMatrix rcpp_get_wecoma_internal(const IntegerMatrix x, const NumericMatrix w, const arma::imat directions, std::vector<int> classes, const std::string fun, const std::string na_action);
static SEXP _comat_rcpp_get_wecoma_internal_try(SEXP xSEXP, SEXP wSEXP, SEXP directionsSEXP, SEXP classesSEXP, SEXP funSEXP, SEXP na_actionSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const IntegerMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< const NumericMatrix >::type w(wSEXP);
    Rcpp::traits::input_parameter< const arma::imat >::type directions(directionsSEXP);
    Rcpp::traits::input_parameter< std::vector<int> >::type classes(classesSEXP);
    Rcpp::traits::input_parameter< const std::string >::type fun(funSEXP);
    Rcpp::traits::input_parameter< const std::string >::type na_action(na_actionSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_get_wecoma_internal(x, w, directions, classes, fun, na_action));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _comat_rcpp_get_wecoma_internal(SEXP xSEXP, SEXP wSEXP, SEXP directionsSEXP, SEXP classesSEXP, SEXP funSEXP, SEXP na_actionSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_comat_rcpp_get_wecoma_internal_try(xSEXP, wSEXP, directionsSEXP, classesSEXP, funSEXP, na_actionSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// triangular_index
int triangular_index(int r, int c);
RcppExport SEXP _comat_triangular_index(SEXP rSEXP, SEXP cSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type r(rSEXP);
    Rcpp::traits::input_parameter< int >::type c(cSEXP);
    rcpp_result_gen = Rcpp::wrap(triangular_index(r, c));
    return rcpp_result_gen;
END_RCPP
}

// validate (ensure exported C++ functions exist before calling them)
static int _comat_RcppExport_validate(const char* sig) { 
    static std::set<std::string> signatures;
    if (signatures.empty()) {
        signatures.insert("double(*rcpp_get_entropy)(NumericVector,std::string)");
        signatures.insert("int(*get_motifel_size)(int,int,int)");
        signatures.insert("List(*get_motifels_coma)(IntegerMatrix,const arma::imat,int,int,const std::string,const std::string)");
        signatures.insert("List(*get_motifels_wecoma)(IntegerMatrix,NumericMatrix,const arma::imat,int,int,const std::string,const std::string)");
        signatures.insert("List(*get_motifels_cocoma)(IntegerMatrix,IntegerMatrix,const arma::imat,int,int)");
        signatures.insert("List(*get_motifels_incoma)(const List,const arma::imat,int,int,const std::string,const std::string)");
        signatures.insert("std::vector<int>(*get_unique_values)(const Rcpp::IntegerVector&,bool)");
        signatures.insert("IntegerMatrix(*rcpp_get_cocoma)(const IntegerMatrix,const IntegerMatrix,const arma::imat)");
        signatures.insert("IntegerMatrix(*rcpp_get_cocoma_internal)(const IntegerMatrix,const IntegerMatrix,const arma::imat,std::vector<int>,std::vector<int>)");
        signatures.insert("IntegerMatrix(*rcpp_get_coma)(const IntegerMatrix,const arma::imat)");
        signatures.insert("IntegerMatrix(*rcpp_get_coma_internal)(const IntegerMatrix,const arma::imat,std::vector<int>)");
        signatures.insert("IntegerMatrix(*rcpp_get_incoma)(const List,const arma::imat)");
        signatures.insert("IntegerMatrix(*rcpp_get_incoma_internal)(const List,const arma::imat,List)");
        signatures.insert("NumericVector(*rcpp_get_vec)(NumericMatrix,bool)");
        signatures.insert("NumericVector(*rcpp_get_wecove)(NumericMatrix,bool)");
        signatures.insert("NumericMatrix(*rcpp_get_wecoma)(const IntegerMatrix,const NumericMatrix,const arma::imat,const std::string,const std::string)");
        signatures.insert("NumericMatrix(*rcpp_get_wecoma_internal)(const IntegerMatrix,const NumericMatrix,const arma::imat,std::vector<int>,const std::string,const std::string)");
    }
    return signatures.find(sig) != signatures.end();
}

// registerCCallable (register entry points for exported C++ functions)
RcppExport SEXP _comat_RcppExport_registerCCallable() { 
    R_RegisterCCallable("comat", "_comat_rcpp_get_entropy", (DL_FUNC)_comat_rcpp_get_entropy_try);
    R_RegisterCCallable("comat", "_comat_get_motifel_size", (DL_FUNC)_comat_get_motifel_size_try);
    R_RegisterCCallable("comat", "_comat_get_motifels_coma", (DL_FUNC)_comat_get_motifels_coma_try);
    R_RegisterCCallable("comat", "_comat_get_motifels_wecoma", (DL_FUNC)_comat_get_motifels_wecoma_try);
    R_RegisterCCallable("comat", "_comat_get_motifels_cocoma", (DL_FUNC)_comat_get_motifels_cocoma_try);
    R_RegisterCCallable("comat", "_comat_get_motifels_incoma", (DL_FUNC)_comat_get_motifels_incoma_try);
    R_RegisterCCallable("comat", "_comat_get_unique_values", (DL_FUNC)_comat_get_unique_values_try);
    R_RegisterCCallable("comat", "_comat_rcpp_get_cocoma", (DL_FUNC)_comat_rcpp_get_cocoma_try);
    R_RegisterCCallable("comat", "_comat_rcpp_get_cocoma_internal", (DL_FUNC)_comat_rcpp_get_cocoma_internal_try);
    R_RegisterCCallable("comat", "_comat_rcpp_get_coma", (DL_FUNC)_comat_rcpp_get_coma_try);
    R_RegisterCCallable("comat", "_comat_rcpp_get_coma_internal", (DL_FUNC)_comat_rcpp_get_coma_internal_try);
    R_RegisterCCallable("comat", "_comat_rcpp_get_incoma", (DL_FUNC)_comat_rcpp_get_incoma_try);
    R_RegisterCCallable("comat", "_comat_rcpp_get_incoma_internal", (DL_FUNC)_comat_rcpp_get_incoma_internal_try);
    R_RegisterCCallable("comat", "_comat_rcpp_get_vec", (DL_FUNC)_comat_rcpp_get_vec_try);
    R_RegisterCCallable("comat", "_comat_rcpp_get_wecove", (DL_FUNC)_comat_rcpp_get_wecove_try);
    R_RegisterCCallable("comat", "_comat_rcpp_get_wecoma", (DL_FUNC)_comat_rcpp_get_wecoma_try);
    R_RegisterCCallable("comat", "_comat_rcpp_get_wecoma_internal", (DL_FUNC)_comat_rcpp_get_wecoma_internal_try);
    R_RegisterCCallable("comat", "_comat_RcppExport_validate", (DL_FUNC)_comat_RcppExport_validate);
    return R_NilValue;
}

static const R_CallMethodDef CallEntries[] = {
    {"_comat_create_attributes", (DL_FUNC) &_comat_create_attributes, 1},
    {"_comat_rcpp_xy_from_matrix", (DL_FUNC) &_comat_rcpp_xy_from_matrix, 2},
    {"_comat_rcpp_cell_from_xy", (DL_FUNC) &_comat_rcpp_cell_from_xy, 2},
    {"_comat_create_neighborhood", (DL_FUNC) &_comat_create_neighborhood, 1},
    {"_comat_rcpp_get_entropy", (DL_FUNC) &_comat_rcpp_get_entropy, 2},
    {"_comat_get_motifel_size", (DL_FUNC) &_comat_get_motifel_size, 3},
    {"_comat_get_motifels_coma", (DL_FUNC) &_comat_get_motifels_coma, 6},
    {"_comat_get_motifels_wecoma", (DL_FUNC) &_comat_get_motifels_wecoma, 7},
    {"_comat_get_motifels_cocoma", (DL_FUNC) &_comat_get_motifels_cocoma, 5},
    {"_comat_get_motifels_incoma", (DL_FUNC) &_comat_get_motifels_incoma, 6},
    {"_comat_get_unique_values", (DL_FUNC) &_comat_get_unique_values, 2},
    {"_comat_rcpp_get_cocoma", (DL_FUNC) &_comat_rcpp_get_cocoma, 3},
    {"_comat_rcpp_get_cocoma_internal", (DL_FUNC) &_comat_rcpp_get_cocoma_internal, 5},
    {"_comat_rcpp_get_coma", (DL_FUNC) &_comat_rcpp_get_coma, 2},
    {"_comat_rcpp_get_coma_internal", (DL_FUNC) &_comat_rcpp_get_coma_internal, 3},
    {"_comat_rcpp_get_incoma", (DL_FUNC) &_comat_rcpp_get_incoma, 2},
    {"_comat_rcpp_get_incoma_internal", (DL_FUNC) &_comat_rcpp_get_incoma_internal, 3},
    {"_comat_rcpp_get_vec", (DL_FUNC) &_comat_rcpp_get_vec, 2},
    {"_comat_rcpp_get_wecove", (DL_FUNC) &_comat_rcpp_get_wecove, 2},
    {"_comat_rcpp_get_wecoma", (DL_FUNC) &_comat_rcpp_get_wecoma, 5},
    {"_comat_rcpp_get_wecoma_internal", (DL_FUNC) &_comat_rcpp_get_wecoma_internal, 6},
    {"_comat_triangular_index", (DL_FUNC) &_comat_triangular_index, 2},
    {"_comat_RcppExport_registerCCallable", (DL_FUNC) &_comat_RcppExport_registerCCallable, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_comat(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
