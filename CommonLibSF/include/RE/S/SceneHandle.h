#pragma once

namespace RE::StorageTable
{
   class SceneHandle {
	  public:
	  SceneHandle() = default;
	  virtual ~SceneHandle() = default;

	  static SceneHandle* Get() {
		  using func_t = decltype(&SceneHandle::Get);
		  REL::Relocation<func_t> func{ REL::ID(772600) };
		  return func();
	  }

	  static void WriteGlobalScene(uint32_t* sceneHandleID, uint8_t* sceneData) {
		  using func_t = decltype(&SceneHandle::WriteGlobalScene);
		  REL::Relocation<func_t> func{ REL::ID(95280) };
		  return func(sceneHandleID, sceneData);
	  }

	  void Register(uint32_t* sceneHandleID) {
		  using func_t = decltype(&SceneHandle::Register);
		  REL::Relocation<func_t> func{ REL::ID(94981) };
		  return func(this, sceneHandleID);
	  }
   };
}