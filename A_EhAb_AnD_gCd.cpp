for (int k=0; k<N; k++) 
    { 
        // Initialize maximum value and index for pivot 
        int i_max = k; 
        int v_max = mat[i_max][k]; 
  
        /* find greater amplitude for pivot if any */
        for (int i = k+1; i < N; i++) 
            if (abs(mat[i][k]) > v_max) 
                v_max = mat[i][k], i_max = i; 
  
        /* if a prinicipal diagonal element  is zero, 
         * it denotes that matrix is singular, and 
         * will lead to a division-by-zero later. */
        if (!mat[k][i_max]) 
            return k; // Matrix is singular 
  
        /* Swap the greatest value row with current row */
        if (i_max != k) 
            swap_row(mat, k, i_max); 
  
  
        for (int i=k+1; i<N; i++) 
        { 
            /* factor f to set current row kth element to 0, 
             * and subsequently remaining kth column to 0 */
            double f = mat[i][k]/mat[k][k]; 
  
            /* subtract fth multiple of corresponding kth 
               row element*/
            for (int j=k+1; j<=N; j++) 
                mat[i][j] -= mat[k][j]*f; 
  
            /* filling lower triangular matrix with zeros*/
            mat[i][k] = 0; 
        } 
  
        //print(mat);        //for matrix state 
    } 