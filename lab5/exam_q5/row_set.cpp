#include "row_set.hpp"
#include <iostream>

using namespace std;

#include "row_echelon_form.hpp"

void RowSet::SubBuffer(int r, int c)
{
    NegBuffer();
    AddBuffer(r,c);
    NegBuffer();
}

void RowSet::DivBuffer(int r, int c)
{
  SwapBuffer(r,c);
  bool a=IsZero(r,c);
  SwapBuffer(r,c);

  if(a){
      //0/0
  }else{
      InvBuffer();
      MulBuffer(r,c);
      InvBuffer();
  }
}

void RowSet::ToReducedRowEchelonForm()
{
    to_reduced_row_echelon_form_generic(*this);
}

void RowSet::ShowSparsity(ostream &dst)
{
  for(int r=1;r<=RowCount(); r++){
      for(int c=1; c<ColCount()+1;c++){
          if(IsZero(r,c)){dst << " " << " ";}
          else if(IsUnit(r,c)){dst << "1" << " ";}
          else{dst << "X" << " ";}
      }
      dst << endl;
  }

}

void RowSet::WriteRow(int row, ostream &dst)
{
    for(int c=1; c<ColCount()+1;c++){
	LoadBuffer(row,c);
        WriteBuffer(cout);

    }
}

void RowSet::WriteMatrix(ostream &dst)
{
    for(int r=1;r<=RowCount(); r++){
        WriteRow(r, dst);
        dst<<endl;
    }
}
