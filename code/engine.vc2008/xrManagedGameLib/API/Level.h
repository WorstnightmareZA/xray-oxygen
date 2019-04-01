#pragma once
#include "ClientSpawnManager.h"
#include "PhysicsWorldScripted.h"
#include "ScriptGameObject.h"
#include "API/xrTime.h"
#include "API/WeatherFX.h"
#include "Game.h"

class CLevel;
class CLevelGraph;
class CPatrolPath;

namespace XRay
{
	
	ref class LevelGraph abstract
	{
	public:
		/// <summaru> Return Level ID</summaru>
		property ::System::UInt32 LevelID
		{
			::System::UInt32 get();
		}

		/// <summaru> Return Vertex count</summaru>
		property ::System::UInt32 VertexCount
		{
			::System::UInt32 get();
		}
		static ::System::UInt32 GetVertexId(Fvector position);

	};

	public ref class Level abstract
	{
	internal:
		CLevel* pNativeLevel;
	public:
		using CallBack = void(::System::String^);

	public:
		static property ClientSpawnManager^ ClientSpawnMngr
		{
			ClientSpawnManager^ get();
		}

		/// <summary>Get Name</summary>
		property ::System::String^ Name
		{
			::System::String^ get();
		}
		/// <summary>WeatherFX</summary>
		static property WeatherFX^ WeatherFX
		{
			void set(XRay::WeatherFX^ pFX);
			XRay::WeatherFX^ get();
		}

		/// <summary>Return WfxTime</summary>
		static property float WfxTime
		{
			float get();
		}
		/// <summary>Return rain factor</summary>
		static property float RainFactor
		{
			float get();
		}
		/// <summary>Return level name from a text files</summary>
		static property ::System::String^ LevelName
		{
			::System::String^ get();
		}
		/// <summary>Return or set weather name</summary>
		static property ::System::String^ Weather
		{
			::System::String^ get();
			void set(::System::String^ str);
		}
		/// <summary>Get or set time factor</summary>
		static property float TimeFactor
		{
			float get();
			void set(float fFactor);
		}

		/// <summary>Is level inited</summary>
		static property bool LevelPresent
		{
			bool get();
		}

		static property GameObject^ ViewEntity
		{
			GameObject^ get();
			void set(GameObject^);
		}

		static float HighCoverInDirection(u32 level_vertex_id, const Fvector &direction);
		static float LowCoverInDirection(u32 level_vertex_id, const Fvector &direction);
		static ::System::Numerics::Vector3^ VertexPosition(u32 level_vertex_id);

		/// <summary>Check: Current level vertex be at level</summary>
		static bool ValidVertex(u32 level_vertex_id);

		static ::System::UInt32 VertexInDirection(u32 level_vertex_id, Fvector direction, float max_distance);

		// Map
		/// <summary>Check: Map has is current spot by object ID?</summary>
		static bool MapHasObjectSpot(u16 id, LPCSTR spot_type);
		/// <summary>Set: Set spot to level map by object ID</summary>
		static void MapAddObjectSpot(u16 id, LPCSTR spot_type, LPCSTR text);
		/// <summary>Set: Del spot from level map by object ID</summary>
		static void MapRemoveObjectSpot(u16 id, LPCSTR spot_type);
		/// <summary>Set: Set spot to level map by object ID</summary>
		static void MapAddObjectSpotSer(u16 id, LPCSTR spot_type, LPCSTR text);
		/// <summary>Set: Change spot hint from level map by object ID</summary>
		static void MapChangeSpotHint(u16 id, LPCSTR spot_type, LPCSTR text);

		static bool PatrolPathExists(LPCSTR patrol_path);
		static void PrefetchSnd(LPCSTR name);
		static XRay::PhysicsWorldScripted^ physicsWorldScripted();
		static void AddDialogToRender(XRay::UIDialogWnd^ pDialog);
		static void RemoveDialogFromRender(XRay::UIDialogWnd^ pDialog);
		static void HideIndicators();
		static void HideIndicatorsSafe();
		static void ShowIndicators();

		//static XRay::MEnvironment^ pEnvironment();
		static XRay::EnvDescriptor^  CurrentEnvironment(XRay::MEnvironment^ self);
		static void SpawnPhantom(const Fvector &position);
		static Fbox GetBoundingVolume();
		static void IterateSounds(LPCSTR prefix, u32 max_count, CallBack callback);
		static int GCommunityGoodwill(LPCSTR _community, int _entity_id);
		static void GSetCommunityGoodwill(LPCSTR _community, int _entity_id, int val);
		static void GChangeCommunityGoodwill(LPCSTR _community, int _entity_id, int val);
		static int GGetCommunityRelation(LPCSTR comm_from, LPCSTR comm_to);
		static void GSetCommunityRelation(LPCSTR comm_from, LPCSTR comm_to, int value);
		static int GGetGeneralGoodwillBetween(u16 from, u16 to);
		static void StartTutorial(LPCSTR name);
		static void StopTutorial();
		static ::System::String^ TranslateString(LPCSTR str);
		static bool HasActiveTutotial();
		static void GSend(NET_Packet& P);
		static void UEventGen(NET_Packet& P, u32 _event, u32 _dest);
		static void UEventSend(NET_Packet& P);
		static void SpawnSection(LPCSTR sSection, Fvector3 vPosition, u32 LevelVertexID, u16 ParentID) { SpawnSection(sSection, vPosition, LevelVertexID, ParentID, false); };
		static void SpawnSection(LPCSTR sSection, Fvector3 vPosition, u32 LevelVertexID, u16 ParentID, bool bReturnItem);
		static void ShowMinimap(bool bShow);
		static XRay::ScriptGameObject^ GGetTargetObject();
		static float GGetTargetDist();
		static ::System::UInt32 GGetTargetElement();
		static u8 GetActiveCam();
		static void SetActiveCam(u8 mode);
		static void PatrolPathAdd(LPCSTR patrol_path, CPatrolPath* path);
		static void PatrolPathRemove(LPCSTR patrol_path);
	};
}