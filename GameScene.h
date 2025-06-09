#pragma once
#include "KamataEngine.h"
#include "Player.h"
#include <vector>
#include"Skydome.h"
#include"MapChipField.h"
#include"CameraController.h"


class GameScene
{
public:

	KamataEngine::Model* model_ = nullptr;

	KamataEngine::Model* modelBlock_ = nullptr;

	KamataEngine::Model* modelSkydome_ = nullptr; 

	KamataEngine::Model* modelPlayer_ = nullptr;

	// 初期化
	void Initialize();
	// 更新
	void Update();
	// 描画
	void Draw();
	// デストラクタ
	~GameScene();

	Player* player_ = nullptr;

	Skydome* skydome_ = nullptr;

	//表示ブロック
	void GenerateBlocks();

	MapChipField* mapChipField_;

	CameraController* cameraController_;

private:
	



	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Camera camera_;

	KamataEngine::DebugCamera* debugCamera_ = nullptr;

	std::vector<std::vector<KamataEngine::WorldTransform*>> worldTransformBlocks_;

	bool isDebugCameraActive_ = false;


};
