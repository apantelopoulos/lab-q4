#include "row_echelon_form.hpp"
#include "row_set.hpp"

#include <cassert>

using namespace std;

void to_reduced_row_echelon_form_generic(RowSet &A)
{
  // This is a modification of the pseudo-code from the
  // wikipedia page: https://en.wikipedia.org/wiki/Gaussian_elimination

  int h = 1; /* Initialization of the pivot row */
  int k = 1; /* Initialization of the pivot column */

  while( h <= A.RowCount() && k <= A.ColCount()){
      /* Find the k-th pivot: */
      //i_max := argmax (i = h ... m, abs(A[i, k]))
      int i_max = h;
      for(int i=h; i<=A.RowCount(); i++){
          A.LoadBuffer(i_max,k);
          if(A.MaxAbsBuffer(i,k)){
              i_max=i;
          }
      }

      if(A.IsZero(i_max,k) == 0){
          /* No pivot in this column, pass to next column */
          k = k+1;
      }
      else{
          /* Move the pivot row to the correct place */
          A.SwapRows(h,i_max);

          /* Normalise the pivot row value to 1 */

          //float f = 1 / m_A[h][k];
          for(int c = A.ColCount(); c>=1; c--){
            A.UnitBuffer();
            A.DivBuffer(h,k);
              A.MulBuffer(h,c);
              A.StoreBuffer(h,c);
  //            m_A[h][c] *= f;
          }
          /* Force pivot value to exactly one */
          A.UnitBuffer();
          A.StoreBuffer(h,k);
          //m_A[h][k]=1;

                    /* Do for all rows except pivot: */
                    for(int i = 1 ; i<=A.RowCount() ; i++){
                        if(i!=h){
                            //float f = m_A[i][k] / m_A[h][k];

                            /* Subtract f * m_A[h]: */
                            for(int j = k + 1 ; j<=A.ColCount() ; j++){
                              A.LoadBuffer(i,k);
                              A.DivBuffer(h,k);
                              A.MulBuffer(h,j);
                              A.SubBuffer(i,j);
                              A.NegBuffer();
                              A.StoreBuffer(i,j);
                                //m_A[i][j] -= f * m_A[h][j];
                            }

                            /* Set pivot column to exactly zero: */
                            A.ZeroBuffer();
                            A.StoreBuffer(i,k);
                            //m_A[i][k] = 0;
                        }
                    }
                    /* Increase pivot row and column */
                    h = h + 1;
                    k = k + 1;
      }
      }

    }
