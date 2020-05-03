#ifndef row_set_float_hpp
#define row_set_float_hpp

#include <complex>
#include "row_set.hpp"

#include <vector>

class RowSetFloat
    : public RowSet
{
private:
    int m_r;
    int m_c;
    vector<vector<complex<double>>> m_A;
    complex<double> m_B;
public:
    virtual std::string FieldName() const;

    virtual int RowCount() const override;
   // { return m_r; }

    virtual int ColCount() const override; 
//    { return m_c; }

    virtual void Resize(int rows, int cols) override;
  /*  {
        m_A.resize(rows+1);
        for(int r=1; r<=rows; r++){
            m_A[r].resize(cols+1);
        }
        m_r=rows;
        m_c=cols;
    }*/

    virtual void ZeroBuffer() override;
    //{ m_B = 0; }

    virtual void UnitBuffer() override;
    //{ m_B = 1; }

    virtual void SwapBuffer(int r, int c) override;
   // { swap( m_B, m_A[r][c]); }

    virtual void LoadBuffer(int r, int c) override;
//    { m_B = m_A[r][c]; }

    virtual void StoreBuffer(int r, int c) override;
  //  { m_A[r][c] = m_B; }

    virtual void MulBuffer(int r, int c) override;
   // { m_B *= m_A[r][c]; }

    virtual void AddBuffer(int r, int c) override;
   // { m_B += m_A[r][c]; }

    // B = - B
    virtual void NegBuffer() override;
    //{ m_B = -m_B; }

    virtual void InvBuffer() override;
    //{ m_B = 1 / m_B; }

    virtual bool MaxAbsBuffer(int r, int c) override;
/*    {
        if(abs(m_A[r][c]) > abs(m_B)){
            m_B=m_A[r][c];
            return true;
        }else{
            return false;
        }
    }*/

    virtual ostream &WriteBuffer(std::ostream &dst) const override;
   // { return dst << m_B; }

    virtual istream &ReadBuffer(std::istream &dst) override;
   // { return dst >> m_B; }

    virtual bool IsUnit(int r, int c) const override;
   // { return m_A[r][c]==1; }
    
    virtual bool IsZero(int r, int c) const override;
   // { return m_A[r][c]==0; }
    
    virtual void SwapRows(int r1, int r2) override;
   // { swap(m_A[r1], m_A[r2] ); }

    virtual void MultiplyRow(int row) override;
/*    {
        for(int c=1; c<=m_c; c++){
            m_A[row][c] *= m_B;  
        }
    }*/

    virtual void AddMultipleOfRow(int row, int src_row) override;
  /*  {
        for(int c=1; c<=m_c; c++){
            m_A[row][c] += m_B * m_A[src_row][c];  
        }
    }*/

};
#endif
