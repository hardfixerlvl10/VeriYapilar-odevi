// Basitçe diziyi sıraladıktan sonra şu mantığı kullanabilirsin:
void ozelSirala(int arr[], int n) {
    // Önce standart bir sıralama yap (Selection Sort gibi)
    selectionSort(arr, n); 
    
    int temp[n];
    int sol = 0, sag = n - 1, k = 0;
    
    while (sol <= sag) {
        if (k % 2 == 0) temp[k++] = arr[sag--]; // Önce büyük
        else temp[k++] = arr[sol++];           // Sonra küçük
    }
    
    for(int i=0; i<n; i++) arr[i] = temp[i];
}
