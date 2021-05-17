#include <bits/stdc++.h>

using namespace std;

vector <int> heap;

void urca(int poz)
{
    while(poz)
    {
        int tata = (poz-1)/2;
        if(heap[tata] < heap[poz])
        {
            swap(heap[tata], heap[poz]);
            poz = tata;
        }
        else{
            break;
        }
    }
}

void coboara(int poz)
{
    if(poz*2+1 >= (int)heap.size())
        return;
    int fiu_st = heap[poz*2+1];
    int fiu_dr = heap[poz*2+2];
    if((poz*2+2 == (int)heap.size()) || fiu_st > fiu_dr)
    {
        if(fiu_st > heap[poz])
        {
            swap(heap[poz], heap[poz*2+1]);
            coboara(poz*2+1);
            return;
        }
        else{
            return;
        }
    }
    else
    {
        if(fiu_dr > heap[poz])
        {
            swap(heap[poz], heap[poz*2+2]);
            coboara(poz*2+2);
            return;
        }
        else{
            return;
        }
    }
}

void insert_heap(int x)
{
    heap.push_back(x);
    urca(heap.size()-1);
}

void delete_max()
{
    if(heap.size()==0)
        return;
    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    coboara(0);
}

int find_max()
{
    if(heap.size() == 0)
        return -1;
    else return heap[0];
}

int find_min()
{
    if(heap.size() == 0)
        return -1;
    else
    {
        int Min = heap[heap.size()-1];
        for(int i=heap.size()-2; i>=(int)heap.size()/2; i--)
        {
            if(heap[i] < Min)
            {
                Min = heap[i];
            }
        }
        return Min;
    }
}

void elimina(int poz)
{
    heap[poz] = heap[heap.size()-1];
    heap.pop_back();
    coboara(poz);
    urca(poz);
}

void delete_min()
{
    if(heap.size()==0)
        return;
    else
    {
        int poz_min = heap.size() - 1;
        for(int i = heap.size()-2; i>=(int)heap.size()/2; i--)
        {
            if(heap[i] <  heap[poz_min])
                poz_min = i;
        }
        elimina(poz_min);
        return;
    }
}

void build_heap(int n, int v[])
{
    for(int i=0; i<n; i++)
        insert_heap(v[i]);
}

void afisare_heap()
{
    cout<<'\n';
    for(int i=0; i<(int)heap.size(); i++)
        cout << heap[i] << ' ';
    cout<<endl;
}

void meniu()
{
    cout<<"1. Insert";
    cout<<"\n2. Delete min";
    cout<<"\n3. Delete max";
    cout<<"\n4. Print min";
    cout<<"\n5. Print max";
    cout<<"\n6. Build heap";
    cout<<"\n7. Afisare heap";
    cout<<"\n8. Stop";
}

int main()
{
    meniu();
    int comanda = 1;
    while(comanda)
    {
        cout<<"\nComanda: ";
        cin>>comanda;
        switch(comanda)
            {
            case 1:
                {
                    int x;
                    cout<<"\nIntroduceti un numar: ";
                    cin>>x;
                    insert_heap(x);
                    break;
                }
            case 2:
                {
                    delete_min();
                    break;
                }
            case 3:
                {
                    delete_max();
                    break;
                }
            case 4:
                {
                    cout<< "\nMinimul este: "<<find_min()<<endl;
                    break;
                }
            case 5:
                {
                    cout<<"\nMaximul este: "<<find_max()<<endl;
                    break;
                }
            case 6:
                {
                    int n;
                    cout<<"\nN = ";
                    cin>>n;
                    int v[n];
                    cout<<"\nIntroduceti "<< n<<" numere: ";
                    for(int i=0; i<n; i++)
                        cin>>v[i];
                    build_heap(n, v);
                    break;
                }
            case 7:
                {
                    afisare_heap();
                    break;
                }
            default:
                {
                    comanda = 0;
                    break;
                }
            }
    }
    return 0;
}
