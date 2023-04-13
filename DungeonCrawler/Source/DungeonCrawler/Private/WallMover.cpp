#include "WallMover.h"
#include "Math/UnrealMathUtility.h"

UWallMover::UWallMover()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UWallMover::BeginPlay()
{
	Super::BeginPlay();
	StartingLocation = GetOwner()->GetActorLocation();
}

void UWallMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (MoveTriggered)
	{
		FVector CurrentLocation = GetOwner()->GetActorLocation();
		FVector TargetLocation = StartingLocation + MoveOffset;
		float Speed = FVector::Distance(StartingLocation, TargetLocation) / MoveTime;
		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
		GetOwner()->SetActorLocation(NewLocation);
	}
}

void UWallMover::SetMoveTriggered(bool NewMoveTriggered)
{
	MoveTriggered = NewMoveTriggered;
}