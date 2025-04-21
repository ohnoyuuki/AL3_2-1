#include "Player.h"
using namespace KamataEngine;


void Player::Initialize(KamataEngine::Model* model, uint32_t textureHandle,KamataEngine::Camera* camera) {
	assert(model);
	model_ = model;
	textureHandle_ = textureHandle;
	camera_ = camera;
	worldTransform_.Initialize();
}

void Player::Update()
{
	worldTransform_.TransferMatrix();
}

void Player::Draw() 
{ 
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	Model::PreDraw(dxCommon->GetCommandList());
	model_->Draw(worldTransform_,*camera_, textureHandle_);
	Model::PostDraw();
}

