#ifndef BLAS_SYRK_HH
#define BLAS_SYRK_HH

#include "blas_fortran.hh"
#include "blas_util.hh"

#include <limits>

namespace blas {

// =============================================================================
// Overloaded wrappers for s, d, c, z precisions.

// -----------------------------------------------------------------------------
/// @ingroup syrk
inline
void syrk(
    blas::Layout layout,
    blas::Uplo uplo,
    blas::Op trans,
    int64_t n, int64_t k,
    float alpha,
    float const *A, int64_t lda,
    float beta,
    float       *C, int64_t ldc )
{
    // check arguments
    throw_if_( layout != Layout::ColMajor &&
               layout != Layout::RowMajor );
    throw_if_( uplo != Uplo::Lower &&
               uplo != Uplo::Upper );
    throw_if_( trans != Op::NoTrans &&
               trans != Op::Trans &&
               trans != Op::ConjTrans );
    throw_if_( n < 0 );
    throw_if_( k < 0 );

    if ((trans == Op::NoTrans) ^ (layout == Layout::RowMajor))
        throw_if_( lda < n );
    else
        throw_if_( lda < k );

    throw_if_( ldc < n );

    // check for overflow in native BLAS integer type, if smaller than int64_t
    if (sizeof(int64_t) > sizeof(blas_int)) {
        throw_if_( n   > std::numeric_limits<blas_int>::max() );
        throw_if_( k   > std::numeric_limits<blas_int>::max() );
        throw_if_( lda > std::numeric_limits<blas_int>::max() );
        throw_if_( ldc > std::numeric_limits<blas_int>::max() );
    }

    blas_int n_   = (blas_int) n;
    blas_int k_   = (blas_int) k;
    blas_int lda_ = (blas_int) lda;
    blas_int ldc_ = (blas_int) ldc;

    if (layout == Layout::RowMajor) {
        // swap lower <=> upper
        // A => A^T; A^T => A; A^H => A
        uplo = (uplo == Uplo::Lower ? Uplo::Upper : Uplo::Lower);
        trans = (trans == Op::NoTrans ? Op::Trans : Op::NoTrans);
    }

    char uplo_ = uplo2char( uplo );
    char trans_ = op2char( trans );
    f77_ssyrk( &uplo_, &trans_, &n_, &k_,
               &alpha, A, &lda_, &beta, C, &ldc_ );
}

// -----------------------------------------------------------------------------
/// @ingroup syrk
inline
void syrk(
    blas::Layout layout,
    blas::Uplo uplo,
    blas::Op trans,
    int64_t n, int64_t k,
    double alpha,
    double const *A, int64_t lda,
    double beta,
    double       *C, int64_t ldc )
{
    // check arguments
    throw_if_( layout != Layout::ColMajor &&
               layout != Layout::RowMajor );
    throw_if_( uplo != Uplo::Lower &&
               uplo != Uplo::Upper );
    throw_if_( trans != Op::NoTrans &&
               trans != Op::Trans &&
               trans != Op::ConjTrans );
    throw_if_( n < 0 );
    throw_if_( k < 0 );

    if ((trans == Op::NoTrans) ^ (layout == Layout::RowMajor))
        throw_if_( lda < n );
    else
        throw_if_( lda < k );

    throw_if_( ldc < n );

    // check for overflow in native BLAS integer type, if smaller than int64_t
    if (sizeof(int64_t) > sizeof(blas_int)) {
        throw_if_( n   > std::numeric_limits<blas_int>::max() );
        throw_if_( k   > std::numeric_limits<blas_int>::max() );
        throw_if_( lda > std::numeric_limits<blas_int>::max() );
        throw_if_( ldc > std::numeric_limits<blas_int>::max() );
    }

    blas_int n_   = (blas_int) n;
    blas_int k_   = (blas_int) k;
    blas_int lda_ = (blas_int) lda;
    blas_int ldc_ = (blas_int) ldc;

    if (layout == Layout::RowMajor) {
        // swap lower <=> upper
        // A => A^T; A^T => A; A^H => A
        uplo = (uplo == Uplo::Lower ? Uplo::Upper : Uplo::Lower);
        trans = (trans == Op::NoTrans ? Op::Trans : Op::NoTrans);
    }

    char uplo_ = uplo2char( uplo );
    char trans_ = op2char( trans );
    f77_dsyrk( &uplo_, &trans_, &n_, &k_,
               &alpha, A, &lda_, &beta, C, &ldc_ );
}

// -----------------------------------------------------------------------------
/// @ingroup syrk
inline
void syrk(
    blas::Layout layout,
    blas::Uplo uplo,
    blas::Op trans,
    int64_t n, int64_t k,
    std::complex<float> alpha,
    std::complex<float> const *A, int64_t lda,
    std::complex<float> beta,
    std::complex<float>       *C, int64_t ldc )
{
    // check arguments
    throw_if_( layout != Layout::ColMajor &&
               layout != Layout::RowMajor );
    throw_if_( uplo != Uplo::Lower &&
               uplo != Uplo::Upper );
    throw_if_( trans != Op::NoTrans &&
               trans != Op::Trans );
    throw_if_( n < 0 );
    throw_if_( k < 0 );

    if ((trans == Op::NoTrans) ^ (layout == Layout::RowMajor))
        throw_if_( lda < n );
    else
        throw_if_( lda < k );

    throw_if_( ldc < n );

    // check for overflow in native BLAS integer type, if smaller than int64_t
    if (sizeof(int64_t) > sizeof(blas_int)) {
        throw_if_( n   > std::numeric_limits<blas_int>::max() );
        throw_if_( k   > std::numeric_limits<blas_int>::max() );
        throw_if_( lda > std::numeric_limits<blas_int>::max() );
        throw_if_( ldc > std::numeric_limits<blas_int>::max() );
    }

    blas_int n_   = (blas_int) n;
    blas_int k_   = (blas_int) k;
    blas_int lda_ = (blas_int) lda;
    blas_int ldc_ = (blas_int) ldc;

    if (layout == Layout::RowMajor) {
        // swap lower <=> upper
        // A => A^T; A^T => A; A^H => A
        uplo = (uplo == Uplo::Lower ? Uplo::Upper : Uplo::Lower);
        trans = (trans == Op::NoTrans ? Op::Trans : Op::NoTrans);
    }

    char uplo_ = uplo2char( uplo );
    char trans_ = op2char( trans );
    f77_csyrk( &uplo_, &trans_, &n_, &k_,
               &alpha, A, &lda_, &beta, C, &ldc_ );
}

// -----------------------------------------------------------------------------
/// @ingroup syrk
inline
void syrk(
    blas::Layout layout,
    blas::Uplo uplo,
    blas::Op trans,
    int64_t n, int64_t k,
    std::complex<double> alpha,
    std::complex<double> const *A, int64_t lda,
    std::complex<double> beta,
    std::complex<double>       *C, int64_t ldc )
{
    // check arguments
    throw_if_( layout != Layout::ColMajor &&
               layout != Layout::RowMajor );
    throw_if_( uplo != Uplo::Lower &&
               uplo != Uplo::Upper );
    throw_if_( trans != Op::NoTrans &&
               trans != Op::Trans );
    throw_if_( n < 0 );
    throw_if_( k < 0 );

    if ((trans == Op::NoTrans) ^ (layout == Layout::RowMajor))
        throw_if_( lda < n );
    else
        throw_if_( lda < k );

    throw_if_( ldc < n );

    // check for overflow in native BLAS integer type, if smaller than int64_t
    if (sizeof(int64_t) > sizeof(blas_int)) {
        throw_if_( n   > std::numeric_limits<blas_int>::max() );
        throw_if_( k   > std::numeric_limits<blas_int>::max() );
        throw_if_( lda > std::numeric_limits<blas_int>::max() );
        throw_if_( ldc > std::numeric_limits<blas_int>::max() );
    }

    blas_int n_   = (blas_int) n;
    blas_int k_   = (blas_int) k;
    blas_int lda_ = (blas_int) lda;
    blas_int ldc_ = (blas_int) ldc;

    if (layout == Layout::RowMajor) {
        // swap lower <=> upper
        // A => A^T; A^T => A; A^H => A
        uplo = (uplo == Uplo::Lower ? Uplo::Upper : Uplo::Lower);
        trans = (trans == Op::NoTrans ? Op::Trans : Op::NoTrans);
    }

    char uplo_ = uplo2char( uplo );
    char trans_ = op2char( trans );
    f77_zsyrk( &uplo_, &trans_, &n_, &k_,
               &alpha, A, &lda_, &beta, C, &ldc_ );
}

// =============================================================================
/// Symmetric rank-k update,
///     \f[ C = \alpha A A^T + \beta C, \f]
/// or
///     \f[ C = \alpha A^T A + \beta C, \f]
/// where alpha and beta are scalars, C is an n-by-n symmetric matrix,
/// and A is an n-by-k or k-by-n matrix.
///
/// Generic implementation for arbitrary data types.
/// TODO: generic version not yet implemented.
///
/// @param[in] layout
///     Matrix storage, Layout::ColMajor or Layout::RowMajor.
///
/// @param[in] uplo
///     What part of the matrix C is referenced,
///     the opposite triangle being assumed from symmetry:
///     - Uplo::Lower: only the lower triangular part of C is referenced.
///     - Uplo::Upper: only the upper triangular part of C is referenced.
///
/// @param[in] trans
///     The operation to be performed:
///     - Op::NoTrans: \f$ C = \alpha A A^T + \beta C. \f$
///     - Op::Trans:   \f$ C = \alpha A^T A + \beta C. \f$
///     - In the real    case, Op::ConjTrans is interpreted as Op::Trans.
///       In the complex case, Op::ConjTrans is illegal (see @ref herk instead).
///
/// @param[in] n
///     Number of rows and columns of the matrix C. n >= 0.
///
/// @param[in] k
///     - If trans = NoTrans: number of columns of the matrix A. k >= 0.
///     - Otherwise:          number of rows    of the matrix A. k >= 0.
///
/// @param[in] alpha
///     Scalar alpha. If alpha is zero, A is not accessed.
///
/// @param[in] A
///     - If trans = NoTrans:
///       the n-by-k matrix A, stored in an lda-by-k array [RowMajor: n-by-lda].
///     - Otherwise:
///       the k-by-n matrix A, stored in an lda-by-n array [RowMajor: k-by-lda].
///
/// @param[in] lda
///     Leading dimension of A.
///     - If trans = NoTrans: lda >= max(1,n) [RowMajor: lda >= max(1,k)],
///     - Otherwise:              lda >= max(1,k) [RowMajor: lda >= max(1,n)].
///
/// @param[in] beta
///     Scalar beta. If beta is zero, C need not be set on input.
///
/// @param[in] C
///     The n-by-n symmetric matrix C,
///     stored in an lda-by-n array [RowMajor: n-by-lda].
///
/// @param[in] ldc
///     Leading dimension of C. ldc >= max(1,n).
///
/// @ingroup syrk

template< typename TA, typename TB, typename TC >
void syrk(
    blas::Layout layout,
    blas::Uplo uplo,
    blas::Op trans,
    int64_t n, int64_t k,
    typename traits3<TA, TB, TC>::scalar_t alpha,
    TA const *A, int64_t lda,
    typename traits3<TA, TB, TC>::scalar_t beta,
    TC       *C, int64_t ldc )
{
    throw std::exception();  // not yet implemented
}

}  // namespace blas

#endif        //  #ifndef BLAS_SYMM_HH
