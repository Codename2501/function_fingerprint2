#!/bin/bash

# Cプログラムをコンパイル
gcc framework.c -o framework -lm

# データファイルを初期化 (空ファイルを作成)
rm -f framework.dat
touch framework.dat

# Gnuplotをバックグラウンドで起動し、プロセスIDを保存
# -p (persist) オプションは手動でkillするため不要
gnuplot framework.gp &
GNUPLOT_PID=$!

echo "Gnuplot (PID: $GNUPLOT_PID) を起動し、データ生成を開始します..."

# Cプログラムを実行し、出力をデータファイルにリダイレクト
# この処理が完了するまでスクリプトはここで待機する
./framework > framework.dat

# Cプログラムが終了した後の処理
echo "データ生成が完了しました。"
echo "グラフを確認後、このターミナルでEnterキーを押すとGnuplotを終了します。"

# ユーザーがEnterキーを押すのを待つ
read

# バックグラウンドのGnuplotを終了させる
kill $GNUPLOT_PID

echo "処理が完了しました。✅"
