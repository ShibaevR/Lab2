#ifndef LAB2_IMMUTABLE_SEQUENCE_H
#define LAB2_IMMUTABLE_SEQUENCE_H

template <class T>
class ImmutableSequence{
public:
    virtual ~ImmutableSequence() = default;

    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(int index) const = 0;
    virtual ImmutableSequence<T>* GetSubSequence(int start_index, int end_index) const = 0;
    virtual int GetLength() const = 0;

    virtual ImmutableSequence<T>* Append(T item) const = 0;
    virtual ImmutableSequence<T>* Prepend(T item) const = 0;
    virtual ImmutableSequence<T>* InsertAt(T item, int index) const = 0;
    virtual ImmutableSequence<T>* Concat(const ImmutableSequence<T>& sequence) const = 0;

    bool operator==(const ImmutableSequence<T>& sequence) const{
        if(this->GetLength() != sequence.GetLength())
            return false;

        for(int i=0; i < this->GetSize(); i++){
            if(this->Get(i) != sequence.Get(i))
                return false;
        }

        return true;
    }

    bool operator!=(const ImmutableSequence<T>& sequence) const{
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



#endif //LAB2_IMMUTABLE_SEQUENCE_H
