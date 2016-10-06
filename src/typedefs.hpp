#ifndef TYPEDEFS_HPP
#define TYPEDEFS_HPP

namespace tl
{
	
	
	using namespace irr;
	using namespace core;
	using namespace scene;
	using namespace gui;
	using namespace video;
	using namespace io;

	typedef IAnimatedMeshSceneNode AnimNode;

	enum
	{
		ID_IsNotPickable = 0,                                                
		IDFlag_IsPickable = 1 << 0,
		IDFlag_IsHighlightable = 1 << 1
	};

	const f32 MOVEMENT_SPEED = 5.f;
};


#endif //TYPEDEFS_HPP
