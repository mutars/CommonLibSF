#pragma once

#include "SFSE/Impl/PCH.h"

#include "RE/A/AIProcess.h"
#include "RE/A/AVMData.h"
#include "RE/A/Actor.h"
#include "RE/A/ActorEquipManager.h"
#include "RE/A/ActorPackage.h"
#include "RE/A/ActorState.h"
#include "RE/A/ActorValueInfo.h"
#include "RE/A/ActorValueOwner.h"
#include "RE/A/ActorValueStorage.h"
#include "RE/A/ActorValues.h"
#include "RE/A/AlchemyItem.h"
#include "RE/A/Array.h"
#include "RE/A/ArrowProjectile.h"
#include "RE/B/BGSAcousticSpace.h"
#include "RE/B/BGSAimAssistModel.h"
#include "RE/B/BGSAimAssistPoseData.h"
#include "RE/B/BGSAimDownSightModel.h"
#include "RE/B/BGSAimModel.h"
#include "RE/B/BGSAimOpticalSightModel.h"
#include "RE/B/BGSAnimationGraphComponent.h"
#include "RE/B/BGSArtObject.h"
#include "RE/B/BGSAttachParentArray.h"
#include "RE/B/BGSAttackDataForm.h"
#include "RE/B/BGSAudioOcclusionPrimitive.h"
#include "RE/B/BGSBaseForm.h"
#include "RE/B/BGSBendableSpline.h"
#include "RE/B/BGSBiomeMarkerObject.h"
#include "RE/B/BGSBipedObjectForm.h"
#include "RE/B/BGSBlockBashData.h"
#include "RE/B/BGSBodyPartDefs.h"
#include "RE/B/BGSBodyPartInfo.h"
#include "RE/B/BGSConstructibleObject.h"
#include "RE/B/BGSCraftableForm.h"
#include "RE/B/BGSCraftingResourceOwner.h"
#include "RE/B/BGSCraftingUseSound.h"
#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSEditorID.h"
#include "RE/B/BGSEntryPoint.h"
#include "RE/B/BGSEquipIndex.h"
#include "RE/B/BGSEquipSlot.h"
#include "RE/B/BGSEquipType.h"
#include "RE/B/BGSExplosion.h"
#include "RE/B/BGSFeaturedItemMessage.h"
#include "RE/B/BGSForcedLocRefType.h"
#include "RE/B/BGSFormFolderKeywordList.h"
#include "RE/B/BGSGenericBaseForm.h"
#include "RE/B/BGSHazard.h"
#include "RE/B/BGSIdleCollection.h"
#include "RE/B/BGSIdleMarker.h"
#include "RE/B/BGSInstanceNamingRulesForm.h"
#include "RE/B/BGSInventoryInterface.h"
#include "RE/B/BGSInventoryItem.h"
#include "RE/B/BGSInventoryList.h"
#include "RE/B/BGSKeyword.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSLegendaryItem.h"
#include "RE/B/BGSLevGenericBaseForm.h"
#include "RE/B/BGSLevPackIn.h"
#include "RE/B/BGSLevSpaceCell.h"
#include "RE/B/BGSListForm.h"
#include "RE/B/BGSLocalizedString.h"
#include "RE/B/BGSLocalizedStringDL.h"
#include "RE/B/BGSLocation.h"
#include "RE/B/BGSLocationRefType.h"
#include "RE/B/BGSMeleeAimAssistModel.h"
#include "RE/B/BGSMenuDisplayObject.h"
#include "RE/B/BGSMod.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSMovableStatic.h"
#include "RE/B/BGSNativeTerminalForm.h"
#include "RE/B/BGSNavmeshableObject.h"
#include "RE/B/BGSObjectInstance.h"
#include "RE/B/BGSObjectPlacementDefaults.h"
#include "RE/B/BGSOpenCloseForm.h"
#include "RE/B/BGSOutfit.h"
#include "RE/B/BGSOverridePackCollection.h"
#include "RE/B/BGSPackIn.h"
#include "RE/B/BGSPerk.h"
#include "RE/B/BGSPerkRankArray.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/B/BGSPreloadable.h"
#include "RE/B/BGSPreviewTransform.h"
#include "RE/B/BGSProjectedDecal.h"
#include "RE/B/BGSProjectile.h"
#include "RE/B/BGSPropertySheet.h"
#include "RE/B/BGSReflectedForm.h"
#include "RE/B/BGSResearchProjectForm.h"
#include "RE/B/BGSScene.h"
#include "RE/B/BGSSkinForm.h"
#include "RE/B/BGSSnapTemplateComponent.h"
#include "RE/B/BGSSnapTemplateNode.h"
#include "RE/B/BGSSoundEcho.h"
#include "RE/B/BGSStaticCollection.h"
#include "RE/B/BGSTalkingActivator.h"
#include "RE/B/BGSTerminal.h"
#include "RE/B/BGSTerminalMenu.h"
#include "RE/B/BGSTextureModel.h"
#include "RE/B/BGSTextureSet.h"
#include "RE/B/BGSTypedFormValuePair.h"
#include "RE/B/BGSTypedKeywordValueArray.h"
#include "RE/B/BGSVoiceType.h"
#include "RE/B/BGSWeaponBarrelModel.h"
#include "RE/B/BSContainer.h"
#include "RE/B/BSExtraData.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSInputEventReceiver.h"
#include "RE/B/BSInputEventUser.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSLock.h"
#include "RE/B/BSLog.h"
#include "RE/B/BSReflection.h"
#include "RE/B/BSStringPool.h"
#include "RE/B/BSStringT.h"
#include "RE/B/BSSystemFile.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTList.h"
#include "RE/B/BSTOptional.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSTTuple.h"
#include "RE/B/BSTTuple3.h"
#include "RE/B/BarrierProjectile.h"
#include "RE/B/BaseFormComponent.h"
#include "RE/B/BeamProjectile.h"
#include "RE/B/BGSSaveLoadManager.h"
#include "RE/C/CodeTasklet.h"
#include "RE/C/Color.h"
#include "RE/C/CombatGroup.h"
#include "RE/C/ConeProjectile.h"
#include "RE/C/Console.h"
#include "RE/C/ConsoleLog.h"
#include "RE/D/DebuggerMessages.h"
#include "RE/E/EffectArchetypes.h"
#include "RE/E/EffectItem.h"
#include "RE/E/EffectSetting.h"
#include "RE/E/EmitterProjectile.h"
#include "RE/E/EnchantmentItem.h"
#include "RE/E/ErrorLogger.h"
#include "RE/E/ExtraDataList.h"
#include "RE/E/ExtraDataTypes.h"
#include "RE/E/ExtraLock.h"
#include "RE/F/FORM_ENUM_STRING.h"
#include "RE/F/FactionRank.h"
#include "RE/F/FlameProjectile.h"
#include "RE/F/FormTypes.h"
#include "RE/G/GameMenuBase.h"
#include "RE/G/GrenadeProjectile.h"
#include "RE/H/HandlePolicy.h"
#include "RE/I/IAnimationGraphManagerHolder.h"
#include "RE/I/IBGSBaseFormData.h"
#include "RE/I/ICachedErrorMessage.h"
#include "RE/I/IComplexType.h"
#include "RE/I/IFuncCallQuery.h"
#include "RE/I/IFunction.h"
#include "RE/I/IKeywordFormBase.h"
#include "RE/I/IMenu.h"
#include "RE/I/IMovementInterface.h"
#include "RE/I/IMovementPlayerControlsFilter.h"
#include "RE/I/IMovementState.h"
#include "RE/I/IMovementStateStore.h"
#include "RE/I/INIPrefSettingCollection.h"
#include "RE/I/INISettingCollection.h"
#include "RE/I/IObjectHandlePolicy.h"
#include "RE/I/IPostAnimationChannelUpdateFunctor.h"
#include "RE/I/ISavePatcherInterface.h"
#include "RE/I/IStoreAnimationActions.h"
#include "RE/I/IVMDebugInterface.h"
#include "RE/I/IVMFunctionMessageDispatch.h"
#include "RE/I/IVMObjectBindInterface.h"
#include "RE/I/IVMRemoteDebuggerInterface.h"
#include "RE/I/IVMSaveLoadInterface.h"
#include "RE/I/IVirtualMachine.h"
#include "RE/I/ImpactResults.h"
#include "RE/I/InteriorData.h"
#include "RE/I/idLogging.h"
#include "RE/I/idTCP.h"
#include "RE/IDs.h"
#include "RE/IDs_NiRTTI.h"
#include "RE/IDs_RTTI.h"
#include "RE/IDs_VTABLE.h"
#include "RE/L/Location.h"
#include "RE/L/LockPickedEvent.h"
#include "RE/L/Logger.h"
#include "RE/M/MagicItem.h"
#include "RE/M/MagicSystem.h"
#include "RE/M/MagicTarget.h"
#include "RE/M/MemoryManager.h"
#include "RE/M/MenuOpenCloseEvent.h"
#include "RE/M/Misc.h"
#include "RE/M/MissileProjectile.h"
#include "RE/M/msvc.h"
#include "RE/M/Main.h"
#include "RE/N/NativeFunction.h"
#include "RE/N/NativeFunctionBase.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiMatrix3.h"
#include "RE/N/NiPoint2.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiPoint4.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/N/NiTransform.h"
#include "RE/O/Object.h"
#include "RE/O/ObjectBindPolicy.h"
#include "RE/O/ObjectTypeInfo.h"
#include "RE/P/PerkRankData.h"
#include "RE/P/PlasmaProjectile.h"
#include "RE/P/PlayerCamera.h"
#include "RE/P/PlayerCharacter.h"
#include "RE/P/Projectile.h"
#include "RE/P/PropertyGroupInfo.h"
#include "RE/P/PropertyTypeInfo.h"
#include "RE/R/RawFuncCallQuery.h"
#include "RE/R/RegSettingCollection.h"
#include "RE/RTTI.h"
#include "RE/S/SWFToCodeFunctionHandler.h"
#include "RE/S/SavePatcher.h"
#include "RE/S/ScaleformGFxASMovieRootBase.h"
#include "RE/S/ScaleformGFxFileTypeConstants.h"
#include "RE/S/ScaleformGFxFunctionHandler.h"
#include "RE/S/ScaleformGFxMovie.h"
#include "RE/S/ScaleformGFxState.h"
#include "RE/S/ScaleformGFxStateBag.h"
#include "RE/S/ScaleformGFxValue.h"
#include "RE/S/ScaleformPtr.h"
#include "RE/S/ScaleformRefCount.h"
#include "RE/S/Script.h"
#include "RE/S/Setting.h"
#include "RE/S/SettingCollection.h"
#include "RE/S/SettingCollectionList.h"
#include "RE/S/SettingCollectionMap.h"
#include "RE/S/Sexes.h"
#include "RE/S/SpellItem.h"
#include "RE/S/Stack.h"
#include "RE/S/StackFrame.h"
#include "RE/S/Struct.h"
#include "RE/S/StructTypeInfo.h"
#include "RE/T/TBO_InstanceData.h"
#include "RE/T/TESAIForm.h"
#include "RE/T/TESActorBase.h"
#include "RE/T/TESActorBaseData.h"
#include "RE/T/TESAmmo.h"
#include "RE/T/TESBipedModelForm.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESCamera.h"
#include "RE/T/TESCellFullyLoadedEvent.h"
#include "RE/T/TESClass.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESContainer.h"
#include "RE/T/TESContainerChangedEvent.h"
#include "RE/T/TESDataHandler.h"
#include "RE/T/TESDeathEvent.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESEnchantableForm.h"
#include "RE/T/TESFile.h"
#include "RE/T/TESFlora.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFormRefCount.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESFurniture.h"
#include "RE/T/TESGlobal.h"
#include "RE/T/TESGrass.h"
#include "RE/T/TESHandleForm.h"
#include "RE/T/TESImageSpaceModifiableForm.h"
#include "RE/T/TESKey.h"
#include "RE/T/TESLevCharacter.h"
#include "RE/T/TESLevItem.h"
#include "RE/T/TESLevSpell.h"
#include "RE/T/TESLeveledList.h"
#include "RE/T/TESMagicTargetForm.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESNPC.h"
#include "RE/T/TESObject.h"
#include "RE/T/TESObjectACTI.h"
#include "RE/T/TESObjectANIO.h"
#include "RE/T/TESObjectARMA.h"
#include "RE/T/TESObjectARMO.h"
#include "RE/T/TESObjectBOOK.h"
#include "RE/T/TESObjectCELL.h"
#include "RE/T/TESObjectCONT.h"
#include "RE/T/TESObjectDOOR.h"
#include "RE/T/TESObjectLIGH.h"
#include "RE/T/TESObjectLoadedEvent.h"
#include "RE/T/TESObjectMISC.h"
#include "RE/T/TESObjectREFR.h"
#include "RE/T/TESObjectSTAT.h"
#include "RE/T/TESObjectWEAP.h"
#include "RE/T/TESProduceForm.h"
#include "RE/T/TESQuest.h"
#include "RE/T/TESRace.h"
#include "RE/T/TESRaceForm.h"
#include "RE/T/TESResponse.h"
#include "RE/T/TESSound.h"
#include "RE/T/TESSpellList.h"
#include "RE/T/TESTexture.h"
#include "RE/T/TESTopicInfo.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"
#include "RE/T/TESWorldSpace.h"
#include "RE/T/TypeInfo.h"
#include "RE/U/UI.h"
#include "RE/V/Variable.h"
#include "RE/W/WwiseGUID.h"
#include "RE/W/WwiseSoundHook.h"
