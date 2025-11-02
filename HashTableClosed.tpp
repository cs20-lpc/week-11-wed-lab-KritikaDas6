template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    // TO DO:
    int probes=0;
    for (int i=0; i < M; i++){
        probes++;
        int idx = probeIndex(key, i);
        if (!occupied[idx]){
            table[idx] = key;
            N++;
            return probes;
        }
    }

    return 0;
}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    // TO DO:
    int probes =0;
    for(int i =0; i<M; i++){
        int idx = probeIndex(key, i);
        probes++;
        if(!occupied[idx]){
            return {false, probes};
        }

        if(table[idx] == key){
            return {true, probes};
        }   
    }

    return {false, 0};
}
