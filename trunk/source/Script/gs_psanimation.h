#ifndef GS_PSANIMATION_H_INCLUDED
#define GS_PSANIMATION_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSAnimation )
private:
    eCBodyPart_PS * GetBodyPart( gESlot );
    GEBool          PlayBodyPartAni( eCBodyPart_PS *, bCString const &, GEBool );
    GEBool          StopBodyPartAni( eCBodyPart_PS *, GEBool );
public:
    GEBool   AddAttachment( bCString, Entity );
    void     AddForceAtPos( bCVector, bCVector );
    void     ClearStaticPose( void );
    GEFloat  GetAniMaxTime( eAnimShared::eEMotionType ) const;
    GEFloat  GetAniPlayTime( eAnimShared::eEMotionType ) const;
    bCString GetBoneName( GEInt ) const;
    bCMatrix GetBonePose( bCString ) const;
    GEBool   GetDebugMode( void ) const;
    GEBool   GetLastAmbientWasLoop( void ) const;
    GEInt    GetLastAnimationVariation( void ) const;
    bCString GetResourceName( void ) const;
    GEBool   GetShowSkeleton( void ) const;
    GEBool   GetSkeletonName( bCString & ) const;
    GEFloat  GetTargetWeight( eAnimShared::eEMotionType );
    GEBool   HasStaticPose( void ) const;
    GEBool   IsDead( void ) const;
    GEBool   IsValid( void ) const;
    GEBool   NeedsDeathAnimation( void ) const;
    void     PauseControllers( GEBool, GEFloat );
    GEBool   PlayBodyAni( bCString, GEBool );
    GEBool   PlayFacialAni( bCString, GEBool );
    void     PullTo( bCVector, GEFloat );
    void     Reactivate( void );
    GEBool   RemoveAttachment( Entity );
    void     RestoreStaticPose( void );
    void     SaveStaticPose( void );
    void     SetActorFrozen( GEBool );
    void     SetDebugMode( GEBool );
    void     SetLastAmbientWasLoop( GEBool );
    void     SetLastAnimationVariation( GEInt );
    void     SetShowSkeleton( GEBool );
    void     SetTargetWeight( GEFloat, eAnimShared::eEMotionType, GEFloat );
    void     StopAni( GEInt, GEFloat );
    GEBool   StopBodyAni( GEBool );
    GEBool   StopFacialAni( GEBool );
    void     UseAmbientVariationExclusionForNextAnimation( void );
protected:
                     operator eCAnimation_PS *       ( void );
                     operator eCAnimation_PS const * ( void ) const;
    eCAnimation_PS * operator ->                     ( void );
public:
    eCAnimation_PS const * operator -> ( void ) const;
};

#endif
