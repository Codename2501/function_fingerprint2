#include <stdio.h>
#include <math.h>
#include <complex.h>
#include<unistd.h>
// 関数ポインタの型定義（double型を引数に取りdouble型を返す関数）
typedef double (*Func)(double);

/**
 * @brief 指定された関数とその導関数から複素ステップHを計算する
 * @param f0 関数 f(x)
 * @param f1 1階導関数 f'(x)
 * @param f2 2階導関数 f''(x)
 * @param f3 3階導関数 f'''(x)
 * @param x 計算を行う実数の点
 * @param n スケールを調整する整数
 * @return 計算された複素ステップH
 */
double complex calculate_H(Func f0,Func f1, Func f2, Func f3, double x, int n)
{
    // 1. 各導関数から角度θを計算
    double complex h1 = ((1.0+f0(x)*I)/sqrt(1.0+f0(x)*f0(x))); // f0はf(x)なので、f'(x)の代わりにf0を使用
    double complex h2 = ((1.0 + f1(x) * I) / sqrt(1.0 + f1(x) * f1(x)));
    double complex h3 = ((1.0 + f2(x) * I) / sqrt(1.0 + f2(x) * f2(x)));
    double complex h4 = ((1.0 + f3(x) * I) / sqrt(1.0 + f3(x) * f3(x)));


    // 3. H1（平均）とH2（積）を計算
    double complex H1 = (h1 + h2 + h3 + h4) / 4.0;
    double complex H2 =h1 * h2 * h3 * h4;

    // 4. H（H1とH2の幾何平均）を計算
    // csqrtは複素数の平方根を計算する
    //double complex H = csqrt(H1 * H2) * pow(2.0, -n);
    double complex H=(H1+H2)/2.0*pow(2.0,-n);
    return H;
}

// --- 以下は使用例 ---

// 例として f(x) = sin(x) を定義
double f0(double x)
{
    return sin(x)/x;
}

// f'(x) = cos(x)
double f1(double x)
{
    return (x*cos(x)-sin(x))/(x*x);
}

// f''(x) = -sin(x)
double f2(double x)
{
    return ((2-x*x)*sin(x)-2*x*cos(x))/(x*x*x);
}

// f'''(x) = -cos(x)
double f3(double x)
{
    return ((6*x-x*x*x)*cos(x)+(3*x*x-6)*sin(x))/(x*x*x*x);
}

int main(void)
{
    /*FILE *GP = popen("gnuplot", "w");
    if (GP == NULL)
    {
        printf("ファイルを開けません。\n");
        return 1;
    }*/
    // パラメータを設定
    double x; // 計算する点
    int n = 1;      // スケール係数
               // 結果の表示
    //printf("f(x) = sin(x) at x = %.2f, n = %d\n", x, n);
    
    for(x=-10.0;x<10.0;x+=0.01){
        // f(x) = sin(x) の場合のHを計算
        double complex H = calculate_H(f0,f1, f2, f3, x, n);

        // creal()とcimag()で複素数の実部と虚部を取得
        //printf("H = %f + %fi\n", creal(H), cimag(H));
        //fprintf(GP,"%.15f,%.15f\n",creal(H), cimag(H));
        printf("%.15f,%.15f,%.15f\n",x,creal(H),cimag(H));
        //fflush(GP);
        fflush(stdout);
        usleep(10000); // 10ミリ秒の遅延を追加（オプション）
    }
    //fclose(GP);
    return 0;
}
