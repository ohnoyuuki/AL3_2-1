#include "GameScene.h"

using namespace KamataEngine;
// 初期化
void GameScene::Initialize()
{
	textureHandle_ = TextureManager::Load("uvChecker.png");

	model_ = KamataEngine::Model::Create();

	worldTransform_.Initialize();

	camera_.Initialize();
	// 自キャラの生成
	player_ = new Player();
	// 自キャラの初期化
	player_->Initialize(model_, textureHandle_,&camera_);
}
// 更新
void GameScene::Update() 
{
	//自キャラの更新
	player_->Update();
}
// 描画
void GameScene::Draw()
{
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	player_->Draw();

	Model::PostDraw();

	
}
// デストラクタ
GameScene::~GameScene()
{
	delete model_;
	//自キャラの解放
	delete player_;

}