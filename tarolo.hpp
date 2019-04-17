#ifndef TAROLO_H
#define TAROLO_H

template <typename T>
class tarolo {
    T* adat;
    size_t meret;
public:
    tarolo(size_t meret = 0): adat(new T[meret]), meret(meret){}
    tarolo(const tarolo& t){
        meret = t.meret;
        for(size_t i = 0; i < meret; i++)
            adat[i] = t.adat[i];
    }
    tarolo& operator=(const tarolo& t){
        if(this != &t){
            delete[] adat;
            meret = t.meret;
            for(size_t i = 0; i < meret; i++)
                adat[i] = t.adat[i];
        }
        return *this;
    }
    ~tarolo(){ delete[] adat; }

    size_t size() const { return meret; }
    T& operator[](size_t i){
        if(i < meret && i >= 0)
            return adat[i];
        throw("Tulindexelve");
    }
    T& operator[](size_t i) const{
        if(i < meret && i >= 0)
            return adat[i];
        throw("Tulindexelve");
    }
    void push_back(const T& uj){
        T* ujAdat = new T[meret+1];
        for(size_t i = 0; i < meret; i++)
            ujAdat[i] = adat[i];
        ujAdat[meret] = uj;
        delete[] adat;
        adat = ujAdat;
        meret++;
    }
    void remove(const T& t){
        for(size_t i = 0; i < meret; i++){
            if(t == adat[i]){
                for(size_t j = i; j+1 < meret; j++)
                    adat[j] = adat[j+1];
                meret--;
            }
        }
    }
};

#endif // TAROLO_H
