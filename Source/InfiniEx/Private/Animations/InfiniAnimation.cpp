﻿// Copyright Abdulrahman Alhamoudi, 2016 - All rights reserved.

#include "InfiniEx.h"
#include "InfiniAnimation.h"
#include "Animation/AnimInstance.h"

void UInfiniAnimation::Attack() {
	if (AnimMontage) {
		FName CurrentSection = Montage_GetCurrentSection(AnimMontage);
		if (CurrentSection.IsNone())
		{
			Montage_Play(AnimMontage);
		}
	}
}

