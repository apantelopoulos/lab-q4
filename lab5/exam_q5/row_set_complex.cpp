
#include <complex>
#include "row_set.hpp"
#include "row_set_complex.hpp"

#include <vector>

using namespace std;


    virtual std::string RowSetComplex::FieldName() const
    { return "complex"; }

    virtual int RowSetComplex::RowCount() const override
    { return m_r; }

    virtual int RowSetComplex::ColCount() const override
    { return m_c; }

    virtual void RowSetComplex::Resize(int rows, int cols) override
    {
        m_A.resize(rows+1);
        for(int r=1; r<=rows; r++){
            m_A[r].resize(cols+1);
        }
        m_r=rows;
        m_c=cols;
    }

    virtual void RowSetComplex::ZeroBuffer() override
    { real(m_B) = 0;
	imag(m_B) = 0;
	}

    virtual void RowSetComplex::UnitBuffer() override
    { real(m_B) = 1;
	imag(m_B) = 0;
	}

    virtual void RowSetComplex::SwapBuffer(int r, int c) override
    { swap( m_B, m_A[r][c]); }

    virtual void RowSetComplex::LoadBuffer(int r, int c) override
    { m_B = m_A[r][c]; }

    virtual void RowSetComplex::StoreBuffer(int r, int c) override
    { m_A[r][c] = m_B; }

    virtual void RowSetComplex::MulBuffer(int r, int c) override
    { m_B *= m_A[r][c]; }

    virtual void RowSetComplex::AddBuffer(int r, int c) override
    { m_B += m_A[r][c]; }

    // B = - B
    virtual void RowSetComplex::NegBuffer() override
    { m_B = -m_B; }

    virtual void RowSetComplex::InvBuffer() override
    { m_B = 1 / m_B; }

    virtual bool RowSetComplex::MaxAbsBuffer(int r, int c) override
    {
        if(abs(m_A[r][c]) > abs(m_B)){
            m_B=m_A[r][c];
            return true;
        }else{
            return false;
        }
    }

    virtual ostream RowSetComplex::&WriteBuffer(std::ostream &dst) const override
    { return dst << m_B; }

    virtual istream RowSetComplex::&ReadBuffer(std::istream &dst) override
    { return dst >> m_B; }

    virtual bool RowSetComplex::IsUnit(int r, int c) const override
    { if(real(m_A[r][c]) == 1 && imag(m_A[r][c]) == 0){
	return true; }

    virtual bool RowSetComplex::IsZero(int r, int c) const override
    { if(real(m_A[r][c]) == 0 && imag(m_A[r][c]) == 0){
        return true;
	 }

    virtual void RowSetComplex::SwapRows(int r1, int r2) override
    { swap(m_A[r1], m_A[r2] ); }

    virtual void RowSetComplex::MultiplyRow(int row) override
    {
        for(int c=1; c<=m_c; c++){
            m_A[row][c] *= m_B;
        }
    }

    virtual void RowSetComplex::AddMultipleOfRow(int row, int src_row) override
    {
        for(int c=1; c<=m_c; c++){
            m_A[row][c] += m_B * m_A[src_row][c];
        }
    }
/*
    virtual void ToReducedRowEchelonForm() override
    {
        // This is a modification of the pseudo-code from the
        // wikipedia page: https://en.wikipedia.org/wiki/Gaussian_elimination

        int h = 1; /* Initialization of the pivot row
        int k = 1; /* Initialization of the pivot column

        while( h <= m_r && k <= m_c){
            /* Find the k-th pivot:
            //i_max := argmax (i = h ... m, abs(A[i, k]))
            int i_max = h;
            for(int i=h; i<=m_r; i++){
                if( abs(m_A[i][k]) > abs(m_A[i_max][k] )){
                    i_max=i;
                }
            }

            if( m_A[i_max][k] == 0){
                /* No pivot in this column, pass to next column
                k = k+1;
            }else{
                /* Move the pivot row to the correct place
                swap(m_A[h], m_A[i_max]);

                /* Normalise the pivot row value to 1
                float f = 1 / m_A[h][k];
                for(int c = 1; c<=m_c; c++){
                    m_A[h][c] *= f;
                }
                /* Force pivot value to exactly one
                m_A[h][k]=1;

                /* Do for all rows except pivot:
                for(int i = 1 ; i<=m_r ; i++){
                    if(i!=h){
                        float f = m_A[i][k] / m_A[h][k];

                        /* Subtract f * m_A[h]:
                        for(int j = k + 1 ; j<=m_c ; j++){
                            m_A[i][j] -= f * m_A[h][j];
                        }

                        /* Set pivot column to exactly zero:
                        m_A[i][k] = 0;
                    }
                }
                /* Increase pivot row and column
                h = h + 1;
                k = k + 1;
            }
        }
    }
*/
