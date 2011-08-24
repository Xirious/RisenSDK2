#ifndef GS_PSCOLLISIONSHAPE_H_INCLUDED
#define GS_PSCOLLISIONSHAPE_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSCollisionShape, eCCollisionShape_PS )
public:
    GEBool            CreateDynamicShape( eECollisionShapeType, eEShapeGroup, GEFloat );
    GEBool            CreateShape( eECollisionShapeType, eEShapeGroup, bCVector, bCVector );
    GEInt             GetNumTouchingShapes( void );
    eEShapeMaterial   GetPhysicMaterial( void );
    bCString          GetTouchingBone( void ) const;
    eEShapeGroup      GetTouchingShapeGroup( GEU32 );
    eEPropertySetType GetType( void ) const;
    GEBool            IsValid( void ) const;
};

#endif
