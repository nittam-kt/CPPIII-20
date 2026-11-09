#pragma once

#include <UniDx.h>
#include <UniDx/Rigidbody.h>


class Sphere : public UniDx::SphereCollider
{
public:
    Sphere() : SphereCollider(UniDx::Vector3::zero, 1.0f) { }

    // 振り分け用
    virtual bool checkIntersect(
        UniDx::Collider* other,
        UniDx::PhysicsActor* myActor,
        UniDx::PhysicsActor* otherActor) override
    {
        if(auto sphere =
            dynamic_cast<UniDx::SphereCollider*>(other))
        {
            return checkIntersect(sphere, myActor, otherActor);
        }

        return SphereCollider::checkIntersect(
            other, myActor, otherActor);
    }

    // 衝突チェック
    virtual bool checkIntersect(
        UniDx::SphereCollider* other,
        UniDx::PhysicsActor* myActor,
        UniDx::PhysicsActor* otherActor) override;

#if false
    virtual bool checkIntersect(
        UniDx::AABBCollider* other,
        UniDx::PhysicsActor* myActor,
        UniDx::PhysicsActor* otherActor) override;
#endif

private:
	float radius = 1.0f;
};

