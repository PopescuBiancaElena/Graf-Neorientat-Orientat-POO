#include<iostream>
#include<fstream>
using namespace std;
ifstream f("test.in");//pentru graful neorientat
ofstream g("test.out");
ifstream fin("date.in");//pentru graful orientat

class Matrice
{
    int **a;
    int nr_noduri, nr_muchii;
public:
    int getNr_noduri()
    {
        return nr_noduri;
    }
    int getA(int i, int j)
    {
        return a[i][j];
    }
    Matrice(int sizeX, int sizeY);//constructor parametrizat
    Matrice();//constructor de initializare
    Matrice(const Matrice &c);//constructor copiere
    ~Matrice();//destructor
    friend istream& operator>>(istream&, Matrice&);
    friend ostream& operator<<(ostream&, const Matrice&);
    Matrice& operator=(const Matrice &);
};
//Graf orientat
Matrice::Matrice(int sizeX, int sizeY)
{
    int i, j;
    nr_noduri = sizeX;
    nr_muchii = sizeY;
    a = new int*[nr_noduri];
    for(i = 0; i < nr_noduri; i++)
        a[i] = new int[nr_noduri];
    for(i = 0; i < nr_noduri; i++)
        for(j = 0; j < nr_noduri; j++)
            a[i][j] = 0;
}

Matrice::Matrice()
{
    a = new int*;
    nr_noduri = 0;
    nr_muchii = 0;
}

Matrice::Matrice(const Matrice &c)
{
    int i, j;
    nr_noduri = c.nr_noduri;
    nr_muchii = c.nr_muchii;
    delete[]a;
    a = new int*[nr_noduri];
    for(i = 0; i < nr_noduri; i++)
        a[i] = new int[nr_noduri];
    for(i = 0; i < nr_noduri; i++)
        for(j = 0; j < nr_noduri; j++)
            a[i][j] = c.a[i][j];
}

Matrice::~Matrice()
{
    for(int i = 0; i < nr_noduri; i++)
        delete[]a[i];
    delete[]a;
}

istream& operator>>(istream& in, Matrice& Citire)
{
    int nod_x, nod_y, i, j;
    for(i = 0 ; i < Citire.nr_noduri; i++)
        delete []Citire.a[i];
    delete[]Citire.a;
    in>>Citire.nr_noduri;
    in>>Citire.nr_muchii;
    Citire.a = new int*[Citire.nr_noduri];
    for(i = 0; i < Citire.nr_noduri; i++)
        Citire.a[i] = new int[Citire.nr_noduri];
    for(int i = 0; i < Citire.nr_noduri; i++)
        for(j = 0; j < Citire.nr_noduri; j++)
            Citire.a[i][j] = 0;
    for(i = 0; i< Citire.nr_muchii; i++)
    {
        in>>nod_x>>nod_y;
        Citire.a[nod_x][nod_y] = 1;
    }
    return in;
}

ostream& operator<<(ostream& out, const Matrice& Afisare)
{
    int i, j;
    for(i = 0; i < Afisare.nr_noduri; i++)
    {
        for(j = 0; j < Afisare.nr_noduri; j++)
            out<<Afisare.a[i][j]<<" ";
        out<<endl;
    }
    return out;
}

Matrice& Matrice::operator=(const Matrice &m)
{
    int i, j;
    if(a)
    {
       for(i = 0; i < nr_noduri; i++)
            delete[]a[i];
        delete[]a;
    }
    nr_noduri = m.nr_noduri;
    nr_muchii = m.nr_muchii;
    a = new int*[nr_noduri];
    for(i = 0; i < nr_noduri; i++)
        a[i] = new int[nr_noduri];
    for(i = 0; i < nr_noduri; i++)
    {
        for(j = 0; j < nr_noduri; j++)
            a[i][j] = m.a[i][j];
    }
    return *this;
}

class Vector
{
    int dim;
    int *v;
public:
    int getDimensiune()
    {
        return dim;
    }
    int getVect(int i)
    {
        return v[i];
    }
    Vector();//constructor initializere
    Vector(int);//constructor parametrizat
    Vector(const Vector &c);//constructor copiere
    ~Vector();//destructor
    friend istream& operator>>(istream&, Vector&);
    friend ostream& operator<<(ostream&, const Vector&);
    Vector& operator=(const Vector &);
};

Vector::Vector()
{
    dim = 0;
    v = new int;
    *v = 0;
}

Vector::Vector(int n)
{
    int i;
    dim = n;
    v = new int[dim];
    for(i = 0 ; i < dim; i++)
        v[i] = 0;
}

Vector::Vector(const Vector& c)
{
    int i;
    dim = c.dim;
    v = new int[dim];
    for(i = 0 ; i < dim; i++)
        v[i] = c.v[i];
}

Vector::~Vector()
{
    delete[]v;
}

istream& operator>>(istream& in, Vector& Citire)
{
    int nod_x, i;
    delete[]Citire.v;
    in>>Citire.dim;
    Citire.v = new int[Citire.dim];
    for(i = 0; i< Citire.dim; i++)
    {
        in>>nod_x;
        Citire.v[i] = nod_x;
    }
    return in;
}

ostream& operator<<(ostream& out, const Vector& Afisare)
{
    int i;
    for(i = 0; i < Afisare.dim; i++)
        out<<Afisare.v[i]<<" ";
    out<<endl;
    return out;
}

Vector& Vector::operator=(const Vector &ve)
{
    int i;
    for(int i = 0; i < dim; i++)
        if(v[i])
            delete[]v;
    v = new int[ve.dim];
    dim = ve.dim;
    for(i = 0 ; i < dim; i++)
        v[i] = ve.v[i];
    return *this;
}

class Lista
{
    Vector *l;
    int nr_noduri;
public:
    Vector getLista(int i)
    {
        return l[i];
    }
    int getNr_noduri()
    {
        return nr_noduri;
    }
    Lista(); //constructor de initializare
    Lista(int); // constructor de copiere
    Lista(const Lista &c);//constructor cu parametru
    ~Lista(); //destructor
    friend istream& operator>>(istream&, Lista&);
    friend ostream& operator<<(ostream&, const Lista&);
    Lista& operator=(const Lista &);
};

Lista::Lista()
{
    nr_noduri = 0;
    l = new Vector;
    *l = 0;
}

Lista::Lista(int p)
{
    nr_noduri = p;
    l = new Vector[nr_noduri];
}

Lista::Lista(const Lista &c)
{
    int i;
    nr_noduri = c.nr_noduri;
    delete[]l;
    l = new Vector[nr_noduri];
    for(i = 0 ; i < nr_noduri; i++)
        l[i] = c.l[i];
}

Lista::~Lista()
{
    delete[]l;
}

istream& operator>>(istream& in, Lista& Citire)
{
    int i;
    delete Citire.l;
    in>>Citire.nr_noduri;
    Citire.l = new Vector[Citire.nr_noduri];
    for(i = 0 ; i <  Citire.nr_noduri; i++)
        in>>Citire.l[i];

    return in;
}

ostream& operator<<(ostream& out, const Lista& Afisare)
{
    int i;
    for(i = 0; i < Afisare.nr_noduri; i++)
    {
        out<<i<<":";
        out<<Afisare.l[i];
    }
    out<<endl;

    return out;
}

Lista& Lista::operator=(const Lista &li)
{
    int i;
    if(l)
        delete[]l;
    l = new Vector[li.nr_noduri];
    nr_noduri = li.nr_noduri;
    for(i = 0 ; i < nr_noduri; i++)
        l[i] = li.l[i];

    return *this;
}

class Graf
{
protected:
    int *vizitat;
    int conexe ;
    int nr_noduri;
public:
    Graf();//constructor initializare
    Graf(int n);//constructor parametrizat
    ~Graf();//destructor
    Graf(const Graf &c);//constructor copiere
    friend istream& operator>>(istream&, Graf&);
    friend ostream& operator<<(ostream&, Graf&);
    Graf& operator=(const Graf &);
    virtual void Parcurgere_Latime() = 0;
    virtual void Parcurgere_Adancime() = 0;
    virtual void Componente_Conexe() = 0;
    virtual void Graf_Conex() = 0;
    void Vizitat_Initializare();
};

void Graf::Vizitat_Initializare()
{
    for(int i = 0; i < nr_noduri; i++)
        vizitat[i] = 0;
}

Graf::Graf()
{
    vizitat = new int;
    conexe = 0;
    nr_noduri = 0;
}

Graf::Graf(int n)
{
    vizitat = new int[n];
    conexe = 0;
    Vizitat_Initializare();
}

Graf::Graf(const Graf &c)
{
    int i;
    nr_noduri = c.nr_noduri;
    conexe = c.conexe;
    delete[]vizitat;
    vizitat = new int[nr_noduri];
    for(i = 0; i < nr_noduri; i++)
        vizitat[i] = c.vizitat[i];
}

Graf::~Graf()
{
    delete[]vizitat;
}

istream& operator>>(istream& in, Graf& n)
{
    return in;
}

ostream& operator<<(ostream& out, const Graf& ma)
{
    return out;
}

Graf& Graf::operator=(const Graf &g)
{
    int i;
    nr_noduri = g.nr_noduri;
    conexe = g.conexe;
    delete[]vizitat;
    vizitat = new int[nr_noduri];
    for(i = 0; i < nr_noduri ;i++)
        vizitat[i] = g.vizitat[i];
    return *this;
}

class Graf_Neorientat : public Graf
{
    Lista L;
public:
    friend istream& operator>>(istream&, Graf_Neorientat&);
    friend ostream& operator<<(ostream&,const Graf_Neorientat&);
    Graf_Neorientat& operator=(const Graf_Neorientat &);
    Graf_Neorientat();//constructor initializare
    Graf_Neorientat(int n);//constructor parametrizat
    ~Graf_Neorientat();//destructor
    Graf_Neorientat(const Graf_Neorientat &c);//constructor copiere
    void Parcurgere_Adancime();
    void Parcurgere_Latime();
    void Componente_Conexe();
    void Graf_Conex();
};

istream& operator>>(istream& in, Graf_Neorientat& n)
{
    f>>n.L;
    n.nr_noduri = n.L.getNr_noduri();
    return in;
}

ostream& operator<<(ostream& out,const Graf_Neorientat& m)
{
    g<<m.L;
    return out;
}

Graf_Neorientat& Graf_Neorientat::operator=(const Graf_Neorientat &c)
{
    Graf::operator=(c);
    L = c.L;
    return *this;
}

Graf_Neorientat::Graf_Neorientat()
{
    conexe = 0;
    nr_noduri = 0;
}

Graf_Neorientat::Graf_Neorientat(int n):Graf(n)
{
    nr_noduri = n;
    L = Lista(n);
}

Graf_Neorientat::Graf_Neorientat(const Graf_Neorientat&c)
{
    L = c.L;
}

Graf_Neorientat::~Graf_Neorientat()
{}

void Graf_Neorientat::Parcurgere_Latime()
{
    int i, j, *Coada;
    int dim = 1, cate_vizitate = 1;
    conexe = 0;
    Coada = new int[nr_noduri];
    for(i=0; i< nr_noduri; i++)
    {
        vizitat[i] = 0;
        Coada[i] = 0;
    }
    int s = -2;
    while(s != -1)
    {
        for(i = 0; i < nr_noduri; i++)
            if(vizitat[i] == 0)
            {
                conexe++;
                s = i;
                Coada[dim] = s;
                dim++;
                vizitat[s] = conexe;
                g<<s<<" ";
                break;
            }
            else
                s = -1;
        while(cate_vizitate < nr_noduri && dim != 1)
        {
            int primul = Coada[dim - 1];
            int cate = L.getLista(primul).getDimensiune();
            for(j = 0; j < cate; j++)
            {
                int vecin = L.getLista(primul).getVect(j);
                if(vizitat[vecin] == 0)
                {
                    cate_vizitate++;
                    vizitat[vecin]= 1;
                    g<<vecin<<" ";
                    Coada[dim] = vecin;
                    dim++;
                }
            }
            for(i = 0; i < nr_noduri; i++)
                Coada[i] = Coada[i+1];
            dim--;
        }
    }
    delete[]Coada;
}

void Graf_Neorientat::Parcurgere_Adancime()
{
    int *Stiva;
    int i, j, dim = 1, cate_vizitate = 1;
    conexe = 0;
    Stiva = new int[nr_noduri];
    for(i = 0; i < nr_noduri; i++)
    {
        vizitat[i] = 0;
        Stiva[i] = 0;
    }
    int s = -2;
    while(s != -1)
    {
        for(i = 0; i < nr_noduri; i++)
            if(vizitat[i] == 0)
            {
                conexe++;
                s = i;
                vizitat[s] = conexe;
                Stiva[dim] = s;
                dim++;
                g<<s<<" ";
                break;
            }
            else
                s = -1;
        while(cate_vizitate < nr_noduri && dim != 1)
        {
            int primul = Stiva[dim - 1];
            int cate = L.getLista(primul).getDimensiune();
            int vecin_vizitat = 0;
            for(j = 0; j < cate; j++)
            {
                int vecin =  L.getLista(primul).getVect(j);
                if(vizitat[vecin] == 0)
                {
                    cate_vizitate++;
                    vizitat[vecin] = conexe;
                    Stiva[dim] = vecin;
                    dim++;
                    vecin_vizitat = 1;
                    g<<vecin<<" ";
                    break;
                }
            }
            if(vecin_vizitat == 0)
            {
                Stiva[dim-1] = 0;
                dim--;
            }
        }
    }
    delete[]Stiva;
}

void Graf_Neorientat::Componente_Conexe()
{
    int i, j;
    g<<endl;
    for(i = 1; i <= conexe; i++)
    {
        g<<"Componenta conexa:"<<i<<" este formata din nodurile: ";
        for(j = 0; j < nr_noduri; j++)
        {
            if(vizitat[j] == i)
                g<<j<<" ";
        }
        g<<endl;
    }
}

void Graf_Neorientat::Graf_Conex()
{
    int nr = 0, i, j;

    for(i = 1; i <= conexe; i++)
    {
        for(j = 0; j < nr_noduri; j++)
        {
            if(vizitat[j] == i)
            {
                nr++;
                break;
            }
        }
    }
    if(nr != 1)
    {
        g<<"Graf nu e conex";
        g<<endl;
    }
    else
    {
        g<<"Graful este conex";
        g<<endl;
    }
}

class Graf_Orientat :public Graf
{
    Matrice A;
public:
    friend istream& operator>>(istream&, Graf_Orientat&);
    friend ostream& operator<<(ostream&, Graf_Orientat&);
    Graf_Orientat& operator=(const Graf_Orientat &);
    Graf_Orientat();//constructor initializare
    Graf_Orientat(int n);//constructor parametrizat
    ~Graf_Orientat();//destructor
    Graf_Orientat(const Graf_Orientat &c);//constructor copiere
    void Parcurgere_Adancime();
    void Parcurgere_Latime();
    void Componente_Conexe();
    void Graf_Conex();
};

istream& operator>>(istream& in, Graf_Orientat& n)
{
    fin>>n.A;
    n.nr_noduri = n.A.getNr_noduri();
    return in;
}

ostream& operator<<(ostream& out, Graf_Orientat& m)
{
    g<<m.A;
    return out;
}

Graf_Orientat& Graf_Orientat::operator=(const Graf_Orientat &c)
{
    Graf::operator=(c);
    A = c.A;
    return *this;
}

Graf_Orientat::Graf_Orientat()
{
    nr_noduri = 0;
    conexe = 0;
}

Graf_Orientat::Graf_Orientat(int n):Graf(n)
{
    nr_noduri = n;
    A = Matrice(n,n);
}

Graf_Orientat::Graf_Orientat(const Graf_Orientat&c)
{
    A = c.A;
}

Graf_Orientat::~Graf_Orientat()
{}

void Graf_Orientat::Parcurgere_Latime()
{
    int i, j, *Coada;
    int dim = 1, cate_vizitate = 1;
    conexe = 0;
    Coada = new int[nr_noduri];
    for(i=0; i< nr_noduri; i++)
    {
        vizitat[i] = 0;
        Coada[i] = 0;
    }
    int s = -2;
    while(s != -1)
    {
        for(i = 0; i < nr_noduri; i++)
            if(vizitat[i] == 0)
            {
                conexe++;
                s = i;
                Coada[dim] = s;
                dim++;
                vizitat[s] = conexe;
                g<<s<<" ";
                break;
            }
            else
                s = -1;
        while(cate_vizitate < nr_noduri && dim != 1)
        {
            int primul = Coada[dim - 1];
            for(j = 0; j < nr_noduri; j++)
                if(A.getA(primul,j) == 1)
                {
                    int vecin = j;
                    if(vizitat[vecin] == 0)
                    {
                        cate_vizitate++;
                        vizitat[vecin]= 1;
                        g<<vecin<<" ";
                        Coada[dim] = vecin;
                        dim++;
                    }
                }
            for(int l = 0; l < dim - 1; l++)
                Coada[l] = Coada[l+1];
            dim--;
        }
    }
    delete[]Coada;
}

void Graf_Orientat::Parcurgere_Adancime()
{
    int *Stiva;
    int i, j, dim = 0, cate_vizitate = 1;
    conexe = 0;
    Stiva = new int[nr_noduri];
    for(i = 0; i < nr_noduri; i++)
    {
        vizitat[i] = 0;
        Stiva[i] = 0;
    }
    int s = -2;

    while(s != -1)
    {
        for(i = 0; i < nr_noduri; i++)
            if(vizitat[i] == 0)
            {
                conexe++;
                s = i;
                vizitat[s] = conexe;
                Stiva[dim] = s;
                dim++;
                g<<s<<" ";
                break;
            }
            else
                s = -1;
        while(cate_vizitate < nr_noduri && dim != 0)
        {
            int primul = Stiva[dim - 1];
            int vecin_vizitat = 0;
            for(j = 0; j < nr_noduri; j++)
                if(A.getA(primul, j) == 1)
                {
                    int vecin = j;
                    if(vizitat[vecin] == 0)
                    {
                        cate_vizitate++;
                        vizitat[vecin] = conexe;
                        Stiva[dim] = vecin;
                        dim++;
                        vecin_vizitat = 1;
                        g<<vecin<<" ";
                        break;
                    }
                }
            if(vecin_vizitat == 0)
            {
                Stiva[dim-1] = 0;
                dim--;
            }
        }
    }
    delete[]Stiva;
}

void Graf_Orientat::Componente_Conexe()
{
    int i, j;
    g<<endl;
    for(i = 1; i <= conexe; i++)
    {
        g<<"Componenta conexa:"<<i<<" este formata din nodurile: ";
        for(j = 0; j < nr_noduri; j++)
        {
            if(vizitat[j] == i)
                g<<j<<" ";
        }
        g<<endl;
    }

}

void Graf_Orientat::Graf_Conex()
{
    int nr = 0, i, j;

    for(i = 1; i <= conexe; i++)
    {
        for(j = 0; j < nr_noduri; j++)
        {
            if(vizitat[j] == i)
            {
                nr++;
                break;
            }
        }
    }
    if(nr != 1)
    {
        g<<"Graf nu e  tare conex";
        g<<endl;
    }
    else
    {
        g<<"Graful este tare conex";
        g<<endl;
    }
}

int main()
{
    int gr_n, i;
    f>>gr_n;
    Graf_Neorientat *gr1_n = new Graf_Neorientat[gr_n];
    for(i = 0; i < gr_n; i++)
    {
        g<<"GRAFUL NEORIENTAT: "<<i+1<<endl;
        f>>gr1_n[i];
        g<<gr1_n[i]<< " ";
        g<<"Parcurgerea in latime: ";
        gr1_n[i].Parcurgere_Latime();
        g<<endl;
        g<<"Parcurgerea in adancime: ";
        gr1_n[i].Parcurgere_Adancime();
        g<<endl;
        gr1_n[i].Componente_Conexe();
        gr1_n[i].Graf_Conex();
    }
    delete[]gr1_n;

    int gr_o, j;
    fin>>gr_o;
    Graf_Orientat *gr2_o = new Graf_Orientat[gr_o];
    for(j = 0; j < gr_o; j++)
    {
        g<<"GRAFUL ORIENTAT: "<<j+1<<endl;
        fin>>gr2_o[j];
        g<<gr2_o[j]<<" ";
        g<<"Parcurgerea in latime: ";
        gr2_o[j].Parcurgere_Latime();
        g<<endl;
        g<<"Parcurgerea in adancime: ";
        gr2_o[j].Parcurgere_Adancime();
        g<<endl;
        gr2_o[j].Componente_Conexe();
        gr2_o[j].Graf_Conex();
    }

    delete[]gr2_o;

    fin.close();
    f.close();
    g.close();

}

