// NeuralNetwork.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include "Layer.h"
#include "V.h"
#include "M.h"

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<float> vec1({ 1,1,1});
	std::vector<float> vec2({ 0,1,1});
	std::vector<float> vec3({ 0,0,1});

	V v1(vec1);
	V v2(vec2);
	V v3(vec3);

	std::vector<V> m;
	m.push_back(v1);
	m.push_back(v2);
	m.push_back(v3);

	M matrix1(m);
	M matrix2(3, 4, 1.0);
	M matrix3(3, 1, 1.0);
	M matrix4(1, 3, 1.0);

	std::cout << matrix4 * matrix3;
	
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
