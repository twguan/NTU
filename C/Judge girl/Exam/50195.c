#include <stdio.h>

int main(){
    int n, ct = 0;
    int d11 = -1, d12 = -1, d21 = -1, d22 = -1, d31 = -1, d32 = -1;
    int p1 = -1, p2 = -1, p3 = -1;
    int p11=0, p12=0, p21=0, p22=0, p31=0, p32=0;
    int f11, f12, f21, f22, f31, f32;
    while (scanf("%d", &n) != EOF){
        if (n == 1){
            if (p1 >= 0){
                if (d12 < 0){
                    d12 = ct-p1;
                    f11 = p1;
                    f12 = ct;
                }
                else{
                    if(ct-p1 >= d12){
                        if (ct-p1 > d12){
                            d11 = d12;
                            p11 = f11;
                            p12 = f12;
                        }
                        d12 = ct-p1;
                        f11 = p1;
                        f12 = ct;
                    }
                    else if (ct-p1 >= d11){
                        d11 = ct-p1;
                        p11 = p1;
                        p12 = ct;
                    }
                }
            }

            p1 = ct;
        }
        if (n == 2){
            if (p2 >= 0){
                if (d22 < 0){
                    d22 = ct-p2;
                    p21 = p2;
                    p22 = ct;
                    f21 = p2;
                    f22 = ct;
                }
                else{
                    if(ct-p2 >= d22){
                        if (ct-p2 > d22){
                            d21 = d22;
                            p21 = f21;
                            p22 = f22;
                        }
                        d22 = ct-p2;
                        f21 = p2;
                        f22 = ct;
                    }
                    else if (ct-p2 >= d21 && ct-p2 < d22){
                        d21 = ct-p2;
                        p21 = p2;
                        p22 = ct;
                    }
                }
            }
            p2 = ct;
        }
        if (n == 3){
            if (p3 >= 0){
                if (d32 < 0){
                    d32 = ct-p3;
                    p31 = p3;
                    p32 = ct;
                    f31 = p3;
                    f32 = ct;
                }
                else{
                    if(ct-p3 >= d32){
                        if (ct-p3 > d32){
                            d31 = d32;
                            p31 = f31;
                            p32 = f32;
                        }
                        d32 = ct-p3;
                        f31 = p3;
                        f32 = ct;
                    }
                    else if (ct-p3 >= d31 && ct-p3 < d32){
                        d31 = ct-p3;
                        p31 = p3;
                        p32 = ct;
                    }
                }
            }
            p3 = ct;
        }
        ct++;
    }
        printf("%d %d %d\n", d11, p11, p12);
        printf("%d %d %d\n", d21, p21, p22);
        printf("%d %d %d", d31, p31, p32);
    return 0;
}