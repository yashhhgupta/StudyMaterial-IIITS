int arr[] = {3, 8, 9, 5, 6, 2};
    int n = 6;
    printf("\nOrignal Array:- \n");
    print_array(arr, n);
    printf("\nArray at each iterations:-\n");
    int temp = 0;
    int x;
    if (n % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (temp == 0)
            {
                for (int j = 0; j < n; j = j + 2)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        x = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = x;
                    }
                }
                temp = 1;
            }
            else
            {
                for (int j = 1; j < n - 1; j = j + 2)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        x = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = x;
                    }
                }
                temp = 0;
            }
            if (i == 5)
            {
                printf("\nFinal Array\n");
            }
            print_array(arr, n);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (temp == 0)
            {
                for (int j = 0; j < n - 1; j = j + 2)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        x = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = x;
                    }
                }
                temp = 1;
            }
            else
            {
                for (int j = 1; j < n; j = j + 2)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        x = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = x;
                    }
                }
                temp = 0;
            }
            if (i == 5)
            {
                printf("\nFinal Array\n");
            }

            print_array(arr, n);
        }
    }