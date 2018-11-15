#include "stdafx.h"
#include "AnpanManager.h"
#include "Math/Random.h"
#include "Packet/PacketAnpanList.h"
#include "Character/Anpan/Anpan.h"

const int AnpanManager::SpawnInterval = 5000;
const unsigned int AnpanManager::AnpanMax = 100;

// コンストラクタ
AnpanManager::AnpanManager()
	: NextUuid(1)
	, SpawnTime(SpawnInterval)
	, MinHp(10)
	, MaxHp(10)
	, MinAtk(0)
	, MaxAtk(0)
	, MinDef(0)
	, MaxDef(0)
	, MinExp(0)
	, MaxExp(0)
{
}

// 初期化.
void AnpanManager::Initialize(int InMinHp, int InMaxHp, int InMinAtk, int InMaxAtk, int InMinDef, int InMaxDef, int InMinExp, int InMaxExp)
{
	MinHp = InMinHp;
	MaxHp = InMaxHp;
	MinAtk = InMinAtk;
	MaxAtk = InMaxAtk;
	MinDef = InMinDef;
	MaxDef = InMaxDef;
	MinExp = InMinExp;
	MaxExp = InMaxExp;
}


// 毎フレームの処理.
void AnpanManager::Poll(int DeltaTime)
{
	SpawnTime -= DeltaTime;
	if (SpawnTime <= 0)
	{
		SpawnAnpan();
		SpawnTime += SpawnInterval;
	}

	Update(DeltaTime);
}

// 取得.
AnpanPtr AnpanManager::Get(u32 Uuid) const
{
	AnpanMap::const_iterator It = AnpanList.find(Uuid);
	if (It == AnpanList.end()) { return AnpanPtr(); }

	return It->second;
}
// アンパンリストパケットを生成.
void AnpanManager::MakeListPacket(PacketAnpanList &Packet)
{
	for (AnpanMap::iterator It = AnpanList.begin(); It != AnpanList.end(); ++It)
	{
		AnpanSharedPtr pAnpan = It->second;
		const CharacterParameter &Param = pAnpan->GetParameter();
		const Vector2D Position = pAnpan->GetPosition();
		AnpanData Data(It->first, Position.X, Position.Y, pAnpan->GetRotation().Get(),Param.Hp, Param.MaxHp);
		Packet.List.PushBack(Data);
	}
}


// アンパン生成.
void AnpanManager::SpawnAnpan()
{
	if (AnpanList.size() >= AnpanMax) { return; }

	float X = Random::Range<float>(-2500.0f, 2500.0f);
	float Y = Random::Range<float>(-2500.0f, 2500.0f);

	int Hp = Random::Range<int>(MinHp, MaxHp);

	int Atk = Random::Range<int>(MinAtk, MaxAtk);
	int Def = Random::Range<int>(MinDef, MaxDef);

	int Exp = Random::Range<int>(MinExp, MaxExp);

	Anpan *pNewAnpan = new Anpan(Vector2D(X, Y), Hp, Atk, Def, Exp);
	AnpanSharedPtr pAnpan = AnpanSharedPtr(pNewAnpan);

	unsigned int Uuid = NextUuid;
	AnpanList[Uuid] = pAnpan;
	pAnpan->SetUuid(Uuid);

	NextUuid++;

	if (OnSpawn)
	{
		OnSpawn(Uuid, pAnpan);
	}
}

// 更新処理.
void AnpanManager::Update(int DeltaTime)
{
	AnpanMap::iterator It = AnpanList.begin();
	while (It != AnpanList.end())
	{
		if (It->second->IsDead())
		{
			It = AnpanList.erase(It);
		}
		else
		{
			It->second->Poll(DeltaTime);
			++It;
		}
	}
}
