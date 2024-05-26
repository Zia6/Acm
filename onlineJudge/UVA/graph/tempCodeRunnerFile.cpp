        std:: cout << "Matrix " << ++cnt << '\n' ;
        for(int i = 1;i <= R * C;i++){
            if(i % C == 0) std:: cout << ek.edges[i].flow + 1 << '\n';
            else std:: c