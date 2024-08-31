#ifndef LAB2_MUTABLE_SEQUENCE_H
#define LAB2_MUTABLE_SEQUENCE_H

template <class T>
class MutableSequence{
public:
    virtual ~MutableSequence() = default;

    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(int index) const = 0;
    virtual MutableSequence<T>* GetSubSequence(int start_index, int end_index) const = 0;
    virtual int GetLength() const = 0;

    virtual void Set(int index, T item) = 0;
    virtual MutableSequence<T>* Append(T item) = 0;
    virtual MutableSequence<T>* Prepend(T item) = 0;
    virtual MutableSequence<T>* InsertAt(T item, int index) = 0;
    virtual MutableSequence<T>* Concat(const MutableSequence<T>& sequence) const = 0;

    bool operator==(const MutableSequence<T>& sequence) const{
        if(this->GetLength() != sequence.GetLength())
            return false;

        for(int i=0; i < this->GetSize(); i++){
            if(this->Get(i) != sequence.Get(i))
                return false;
        }

        return true;
    }

    bool operator!=(const MutableSequence<T>& sequence) const{
        if(this->GetLength() != sequence.GetLength())
            return true;

        for(int i=0; i < this->GetSize(); i++){
            if(this->Get(i) != sequence.Get(i))
                return true;
        }

        return false;
    }

    virtual bool CheckInitialization() const = 0;
};



#endif //LAB2_MUTABLE_SEQUENCE_H
