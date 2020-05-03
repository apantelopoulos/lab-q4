#include "row_set.hpp"
#include "row_set_factory.hpp"
#include "row_set_float.hpp"

#include <cassert>

int main(int argc, char *argv[])
{
    string field="float";

    if(argc>1){
        field=argv[1];
    }

    RowSet *A = create_row_set(field);

    // We need at least one element to perform the tests,
    // in addition to the buffer
    A->Resize(1,1);

	A->UnitBuffer();
	A->AddBuffer(1,1);
  A->StoreBuffer(1,1);

  if(A->IsUnit(1,1)){
      cout << "Additive identity OK" << endl;
      }
      else{return 1;}

	A->MulBuffer(1,1);
  A->StoreBuffer(1,1);

  if(A->IsUnit(1,1)){
      cout << "Multiplicative identity OK" << endl;
      }
      else{return 1;}

  A->InvBuffer();
  A->InvBuffer();
  A->StoreBuffer(1,1);

  if(A->IsUnit(1,1)){
      cout << "Double negate identity OK" << endl;
      }
      else{return 1;}

  A->InvBuffer();
  A->StoreBuffer(1,1);


  if(A->IsUnit(1,1)){
      cout << "Inverse identity OK" << endl;
      }
      else{return 1;}

return 0;
}
