#include <omp.h>
#include <iostream>
#include <ctime>

using namespace std;

const int N = 100000000;

void main()
{
    srand(time(0));
    double comp = 1;
    int* A = new int[N];
    int* B = new int[N];
    int* C = new int[N];

    for (int i = 0; i < N; i++)
    {
        A[i] = rand() % 10;
        B[i] = rand() % 10;
        C[i] = rand() % 10;
        //cout << A[i] << " " << B[i] << " " << C[i] << endl;
    }


    double start;
    double end;

    start = omp_get_wtime();
#pragma omp parallel shared(A,B,C)// 2 sections
    {
#pragma omp sections reduction(*:comp)
        {
#pragma omp section
            for (int i = 0; i < N/2; i++)
            {
                double cur;
                if (A[i] % 2 == 0)
                {
                    if (B[i] == 0 || C[i] == 0) cur = 1;
                    else cur = B[i] / static_cast<double>(C[i]);
                }
                else
                {
                    if (B[i] == 0 && A[i] == 0) cur = 1;
                    else cur = B[i] + A[i];
                }
                comp *= cur;
            }
#pragma omp section 
            for (int i = N / 2; i < N; i++)
            {
                double cur;
                if (A[i] % 2 == 0)
                {
                    if (B[i] == 0 || C[i] == 0) cur = 1;
                    else cur = B[i] / static_cast<double>(C[i]);
                }
                else
                {
                    if (B[i] == 0 && A[i] == 0) cur = 1;
                    else cur = B[i] + A[i];
                }
                comp *= cur;
            }
        }
    }
    end = omp_get_wtime();
    cout << "\nResult " << comp << endl;
    comp = 1;
    cout << "Time " << end - start << endl;

    int gap = N / 8;
    start = omp_get_wtime();
#pragma omp parallel shared(A,B,C)// 8 sections
    {
#pragma omp sections reduction(*:comp)
        {
#pragma omp section
            for (int i = 0; i < gap; i++)
            {
                double cur;
                if (A[i] % 2 == 0)
                {
                    if (B[i] == 0 || C[i] == 0) cur = 1;
                    else cur = B[i] / static_cast<double>(C[i]);
                }
                else
                {
                    if (B[i] == 0 && A[i] == 0) cur = 1;
                    else cur = B[i] + A[i];
                }
                comp *= cur;
            }
#pragma omp section 
            for (int i = gap; i < 2 * gap; i++)
            {
                double cur;
                if (A[i] % 2 == 0)
                {
                    if (B[i] == 0 || C[i] == 0) cur = 1;
                    else cur = B[i] / static_cast<double>(C[i]);
                }
                else
                {
                    if (B[i] == 0 && A[i] == 0) cur = 1;
                    else cur = B[i] + A[i];
                }
                comp *= cur;
            }
#pragma omp section 
            for (int i = 2 * gap; i < 3 * gap; i++)
            {
                double cur;
                if (A[i] % 2 == 0)
                {
                    if (B[i] == 0 || C[i] == 0) cur = 1;
                    else cur = B[i] / static_cast<double>(C[i]);
                }
                else
                {
                    if (B[i] == 0 && A[i] == 0) cur = 1;
                    else cur = B[i] + A[i];
                }
                comp *= cur;
            }
#pragma omp section 
            for (int i = 3 * gap; i < 4 * gap; i++)
            {
                double cur;
                if (A[i] % 2 == 0)
                {
                    if (B[i] == 0 || C[i] == 0) cur = 1;
                    else cur = B[i] / static_cast<double>(C[i]);
                }
                else
                {
                    if (B[i] == 0 && A[i] == 0) cur = 1;
                    else cur = B[i] + A[i];
                }
                comp *= cur;
            }
#pragma omp section 
            for (int i = 4 * gap; i < 5 * gap; i++)
            {
                double cur;
                if (A[i] % 2 == 0)
                {
                    if (B[i] == 0 || C[i] == 0) cur = 1;
                    else cur = B[i] / static_cast<double>(C[i]);
                }
                else
                {
                    if (B[i] == 0 && A[i] == 0) cur = 1;
                    else cur = B[i] + A[i];
                }
                comp *= cur;
            }
#pragma omp section 
            for (int i = 5 * gap; i < 6 * gap; i++)
            {
                double cur;
                if (A[i] % 2 == 0)
                {
                    if (B[i] == 0 || C[i] == 0) cur = 1;
                    else cur = B[i] / static_cast<double>(C[i]);
                }
                else
                {
                    if (B[i] == 0 && A[i] == 0) cur = 1;
                    else cur = B[i] + A[i];
                }
                comp *= cur;
            }
#pragma omp section 
            for (int i = 6 * gap; i < 7 * gap; i++)
            {
                double cur;
                if (A[i] % 2 == 0)
                {
                    if (B[i] == 0 || C[i] == 0) cur = 1;
                    else cur = B[i] / static_cast<double>(C[i]);
                }
                else
                {
                    if (B[i] == 0 && A[i] == 0) cur = 1;
                    else cur = B[i] + A[i];
                }
                comp *= cur;
            }
#pragma omp section 
            for (int i = 7 * gap; i < N; i++)
            {
                double cur;
                if (A[i] % 2 == 0)
                {
                    if (B[i] == 0 || C[i] == 0) cur = 1;
                    else cur = B[i] / static_cast<double>(C[i]);
                }
                else
                {
                    if (B[i] == 0 && A[i] == 0) cur = 1;
                    else cur = B[i] + A[i];
                }
                comp *= cur;
            }
        }
    }
    end = omp_get_wtime();
    cout << "\nResult " << comp << endl;
    comp = 1;
    cout << "Time " << end - start << endl;


    start = omp_get_wtime();
#pragma omp parallel shared(A,B,C)//lab 3
    {
#pragma omp for reduction(*:comp)
        for (int i = 0; i < N; i++)
        {
            double cur;
            if (A[i] % 2 == 0)
            {
                if (B[i] == 0 || C[i] == 0) cur = 1;
                else cur = B[i] / static_cast<double>(C[i]);
            }
            else
            {
                if (B[i] == 0 && A[i] == 0) cur = 1;
                else cur = B[i] + A[i];
            }
            //cout << cur << " ";

            comp *= cur;
        }
    }
    end = omp_get_wtime();
    cout << "\nResult " << comp << endl;
    comp = 1;
    cout << "Time " << end - start << endl;

}

