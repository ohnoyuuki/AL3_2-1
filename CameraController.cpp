#include "CameraController.h"
#include"Player.h"

void CameraController::Initialize() 
{
	camera_.Initialize();
}

void CameraController::Update() 
{
	//追従対象んぽワールドタランスフォームを参照
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();
	//追従対象とオフセットからカメラの座標を計算
	camera_.translation_ = targetWorldTransform.translation_ + targetOffset_;

	//移動範囲制限
	camera_.translation_.x = max(camera_.translation_.x, movableArea_.left);
	camera_.translation_.x = max(camera_.translation_.x, movableArea_.right);
	camera_.translation_.y = max(camera_.translation_.x, movableArea_.bottom);
	camera_.translation_.y = max(camera_.translation_.x, movableArea_.top);
	//行列を更新する
	camera_.UpdateMatrix();

}

void CameraController::Reset() 
{
    //追従対象のワールドトランスフォームを参照
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();
    //追従対象とオフセットからカメラの座標を計算
	camera_.translation_ = targetWorldTransform.translation_ + targetOffset_;
	//行列を更新する
	camera_.UpdateMatrix();
}
