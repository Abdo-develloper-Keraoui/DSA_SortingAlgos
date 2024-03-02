/*
This program contains the implementation of 5 sorting algorithms in c that belong to two different categories:
                - comparison-based sorting algorithms: Selection Sort, Insertion Sort and Bubble Sort (really slow, aka average and worst cases of time complexities of O(n^2))
                - divide and conquer algorithms: QuickSort(using the Lomuto partition scheme) and Merge Sort (faster for large data sets with an average case of O(n log(n)) )
*/
#include <stdio.h>
#include <stdlib.h>


void Swap(int *T, int n, int m)
{
                int ech;
                ech = T[n];
                T[n] = T[m];
                T[m] = ech;
}

void selection_sort(int* T, int sizeT)
{
                int i,j,posmin;
                for(i=0;i<=sizeT-2;i++)
                {
                                posmin=i;
                                for(j=i+1;j<=sizeT-1;j++)
                                {
                                                if(T[j]<T[posmin])
                                                          posmin = j;
                                }
                                if(posmin != i)
                                                Swap(T,i,posmin);
                }
}

void bubble_sort(int* T, int sizeT)
{
                int i,j;
                for(i=0;i<=sizeT-2;i++)
                {
                                for(j=0;j<=sizeT-(i+1);j++)
                                {
                                                if(T[j]>T[j+1])
                                                                Swap(T,j,j+1);
                                }
                }
}

void insertion_sort(int* T, int sizeT)
{
                int temp, i, j;
                for(i=1;i<=sizeT-1;i++)
                {
                                temp = T[i];
                                j=i;
                                while((j!=0) && (T[j-1]>temp))
                                {
                                                T[j] = T[j-1];
                                                j--;
                                }
                                T[j]=temp;
                }
}

void quicksort(int* T, int g, int d)
{
                int i=g ,j=d ,pivot;
                pivot = T[(i+j)/2];
                do
                {
                                while(T[i]<pivot)
                                                i++;
                                while(T[j]>pivot)
                                                j--;
                                if(i<=j)
                                {
                                                Swap(T,i,j);
                                                i++;
                                                j--;
                                }
                }while(i<=j);
                if(g<j)
                                quicksort(T,g,j);
                if(i<d)
                                quicksort(T,i,d);
}


void Merge(int *T, int deb1, int fin1, int fin2)
{
                int *Tableau1, i, deb2 = fin1+1, compt1 = deb1, compt2 = deb2;
                Tableau1 = (int*)malloc((fin1-deb1+1)*sizeof(int));
                for(i=deb1;i<=fin1;i++)
                {
                                Tableau1[i-deb1] = T[i];
                }
                for(i=deb1;i<=fin2;i++)
                {
                                if(compt1 == deb2)
                                                break;
                                else
                                {
                                                if(compt2 == fin2 +1)
                                                {
                                                                T[i] = Tableau1[compt1-deb1];compt1++;
                                                }
                                                else
                                                {
                                                                if(Tableau1[compt1-deb1]<T[compt2])
                                                                {
                                                                                T[i] = Tableau1[compt1-deb1];compt1++;
                                                                }
                                                                else
                                                                {
                                                                                T[i] = T[compt2];compt2++;
                                                                }
                                                }
                                }
                }
                free(Tableau1);
}

void merge_sort(int* T, int deb, int fin)
{
                if(deb != fin)
                {
                                int milieu = (deb+fin)/2;
                                merge_sort(T,deb,milieu);
                                merge_sort(T,milieu+1,fin);
                                Merge(T,deb,milieu,fin);
                }
}

void Afficher_Tab(int*T, int NbrElemt)
{
                int i;
                printf("{");
                for(i=0;i<NbrElemt-1;i++)
                {
                                printf("%d,", T[i]);
                }
                printf("%d}.\n", T[i]);
}

int main()
{
                int T[] = {15,3,3,4,1000,7,136,2,2,9,70};
                Afficher_Tab(T,11);
                //selection_sort(T,11);
                //bubble_sort(T,11);
                //insertion_sort(T,11);
                //quicksort(T,0,10);
                //merge_sort(T,0,10);
                Afficher_Tab(T,11);
}
