#include <omp.h>
#include <iostream>
#include <ctime>

using namespace std;

const int N = 20000000;

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
    omp_lock_t lock;
    omp_init_lock(&lock);

    start = omp_get_wtime();
#pragma omp parallel shared(A,B,C)// семафорные переменные
    {
#pragma omp for
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
            
            omp_set_lock(&lock);
            comp *= cur;
            omp_unset_lock(&lock);
        }
    }
    end = omp_get_wtime();
    cout << "\nResult " << comp << endl;
    comp = 1;
    cout << "Time " << end - start << endl;


    start = omp_get_wtime();
#pragma omp parallel shared(A,B,C)// lab 3
    {
#pragma omp for nowait
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


            comp *= cur;
        }
    }
#pragma omp barrier
    end = omp_get_wtime();
    cout << "\nResult " << comp << endl;
    comp = 1;
    cout << "Time " << end - start << endl;



    start = omp_get_wtime();
#pragma omp parallel shared(A,B,C)// lab 3
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
            

            comp *= cur;
        }
    }
    end = omp_get_wtime();
    cout << "\nResult " << comp << endl;
    comp = 1;
    cout << "Time " << end - start << endl;

}

