#include "row_set.hpp"

#include "row_echelon_form.hpp"

void RowSet::SubBuffer(int r, int c)
{
    NegBuffer();
    AddBuffer(int r, int c);
    NegBuffer();
}

void RowSet::DivBuffer(int r, int c)
{
    InvBuffer();
    MulBuffer(int r, int c);
    InvBuffer();
}

void RowSet::ToReducedRowEchelonForm()
{
    to_reduced_row_echelon_form_generic(*this);
}

void RowSet::ShowSparsity(ostream &dst)
{
  for(int r=1;r<=RowCount(); r++){
      for(int c=1; i<ColCount()+1;i++){
          if(A[r,c]==0){dst << " " << " "}
          elseif(A[r,c]==1){dst << "1" << " "}
          else{dst << "X" << " "}
      }
      dst << endl;
  }

}

void RowSet::WriteRow(int row, ostream &dst)
{
    for(int c=1; i<ColCount()+1;i++){

        dst << A[row,c] << " "

    }
}

void RowSet::WriteMatrix(ostream &dst)
{
    for(int r=1;r<=RowCount(); r++){
        WriteRow(r, dst);
        dst<<endl;
    }
}
