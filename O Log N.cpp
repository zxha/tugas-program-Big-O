using namespace std;
main(){
    const int arraySize=5;
    int target;
    int array[arraySize]={1,2,3,4,5};
    int first, mid, last;

    cout<<"Masukan angka yang dicari: ";cin>>target;
    first=0;
    last=2;

    while(first<=last)
    {
        mid=(first+last)/2;
        if(target>array[mid])
        {
            first=mid+1;
        }else if(target<array[mid])
        {
            last=mid+1;
        }else{
            first=last+1;
        }
    }
    if(target==array[mid])
    {
        cout<<"Angka ditemukan."<<endl;
    }else{
        cout<<"Angka tidak ditemukan."<<endl;
    }
}
