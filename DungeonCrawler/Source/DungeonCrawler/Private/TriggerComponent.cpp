#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent = GetOwner()->FindComponentByClass<UBoxComponent>();

	if (WallToMove == nullptr) { return; }

	WallMover = WallToMove->FindComponentByClass<UWallMover>();
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (BoxComponent == nullptr) { return; }
	if (WallToMove == nullptr) { return; }

	TArray<AActor*> Actors;
	BoxComponent->GetOverlappingActors(Actors);
	for (AActor* Actor : Actors)
	{
		if (Actor->ActorHasTag("OpenDoor1"))
		{
			WallMover->SetMoveTriggered(true);
		}
	}
}