#include "Sphere.h"

using namespace UniDx;


bool Sphere::checkIntersect(
	SphereCollider* other,
	PhysicsActor* myActor,
	PhysicsActor* otherActor)
{
	Vector3 centerA = transform->TransformPoint(center);
	float radiusA = radius;
	Vector3 centerB = other->transform->TransformPoint(other->center);
	float radiusB = other->radius;

	if(Distance(centerA, centerB) > radiusA + radiusB) return false;

	// 差分ベクトル
	Vector3 diff = centerB - centerA;

	// 方向ベクトル
	Vector3 direction = diff.normalized();

	// 深さ
	float penetration = (radiusA + radiusB) - Distance(centerA, centerB);

	// めりこみ解消ベクトル
	Vector3 addA = direction * (penetration * -0.5f);
	Vector3 addB = direction * (penetration * 0.5f);

	// ベクトルを登録
	myActor->addCorrectPosition(addA);
	otherActor->addCorrectPosition(addB);

	return false;
}


#if false
bool Sphere::checkIntersect(
	AABBCollider* other,
	PhysicsActor* myActor,
	PhysicsActor* otherActor)
{
	return false;
}
#endif