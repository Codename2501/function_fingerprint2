# グラフの各種設定
set title "framework method"
set xlabel "実軸"
set ylabel "虚軸"
set grid
# 凡例の位置を指定する場合は、行頭の 'S' を削除しコメントを外す
set key top left

# 区切り文字がカンマであることを宣言
set datafile separator ','

# 軸の範囲を固定
set xrange [-1:1]
set yrange [-1:1]

# 最初に描画する内容を定義
# 1列目をX軸、2列目をY軸としてプロット
plot 'framework.dat' using 1:2 with lines title "実軸", \
      'framework.dat' using 1:3 with lines title "虚軸", \
      'framework.dat' using 2:3 with lines title "実軸・虚軸"
     #'framework.dat' using 1:3 with points pointsize 0.005 title "v"
     #'hybrid.dat' using 1:4 with points pointsize 1 title "dt"

# whileループでグラフを繰り返し更新
while (1) {
  # 0.1秒待機
  pause 0.1
  # 直前のplotコマンドを再実行
  replot
}
