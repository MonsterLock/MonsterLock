/*
R.A. Bickell [https://github.com/MonsterLock]
ML_Vector.cpp Last Updated: 2019-09-19 03::07::51 AM
*/
#include "ML_Vector.h"

using namespace ML::MATH::Vector;

vector::vector( ) noexcept
	: x( 0.0f ) , y( 0.0f ) , z( 0.0f ) , w( 0.0f )
{
}

vector::vector( const float& x , const float& y ) noexcept
	: x( x ) , y( y ) , z( 0.0f ) , w( 0.0f )
{
}

vector::vector( const float& x , const float& y , const float& z ) noexcept
	: x( x ) , y( y ) , z( z ) , w( 0.0f )
{
}

vector::vector( const float& x , const float& y , const float& z , const float& w ) noexcept
	: x( x ) , y( y ) , z( z ) , w( w )
{
}

vector::vector( const vector& rhs ) noexcept
	: x( rhs.x ) , y( rhs.y ) , z( rhs.z ) , w( rhs.w )
{
}

// Uses 'IsAboutEqual' comparison. For exact equality check use 'IsExact'.
bool vector::operator==( const vector& rhs )
{
	return
		IsAboutEqual( this->x , rhs.x ) &&
		IsAboutEqual( this->y , rhs.y ) &&
		IsAboutEqual( this->z , rhs.z ) &&
		IsAboutEqual( this->w , rhs.w );
}

// Uses 'IsAboutEqual' comparison. For exact equality check use 'IsExact'.
bool vector::operator!=( const vector& rhs )
{
	return
		!( IsAboutEqual( this->x , rhs.x ) &&
		   IsAboutEqual( this->y , rhs.y ) &&
		   IsAboutEqual( this->z , rhs.z ) &&
		   IsAboutEqual( this->w , rhs.w ) );
}

float vector::operator*( const vector& rhs ) const
{
	return
		this->x * rhs.x +
		this->y * rhs.y +
		this->z * rhs.z +
		this->w * rhs.w;
}

float vector::operator[]( const unsigned int index )
{
	return e[ index ];
}

const float vector::operator[]( const unsigned int index ) const
{
	return e[ index ];
}

vector& vector::operator=( const vector& rhs )
{
	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;
	this->w = rhs.w;
	return *this;
}

vector vector::operator+( const vector& rhs ) const
{
	return vector(
		this->x + rhs.x ,
		this->y + rhs.y ,
		this->z + rhs.z ,
		this->w + rhs.w );
}

vector& vector::operator+=( const vector& rhs )
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	this->w += rhs.w;
	return *this;
}

vector vector::operator-( ) const
{
	return vector(
		-this->x ,
		-this->y ,
		-this->z ,
		-this->w );
}

vector vector::operator-( const vector& rhs ) const
{
	return vector(
		this->x - rhs.x ,
		this->y - rhs.y ,
		this->z - rhs.z ,
		this->w - rhs.w );
}

vector& vector::operator-=( const vector& rhs )
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	this->w -= rhs.w;
	return *this;
}

vector vector::operator*( const float& rhs ) const
{
	return vector(
		this->x * rhs ,
		this->y * rhs ,
		this->z * rhs ,
		this->w * rhs );
}

vector& vector::operator*=( const float& rhs )
{
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;
	this->w *= rhs;
	return *this;
}

// Inverses value and does scalar multiplication.
vector vector::operator/( const float& rhs ) const
{
	float inverse = 1.0f / rhs;
	return vector(
		this->x * inverse ,
		this->y * inverse ,
		this->z * inverse ,
		this->w * inverse );
}

// Inverses value and does scalar multiplication.
vector& vector::operator/=( const float& rhs )
{
	float inverse = 1.0f / rhs;
	this->x *= inverse;
	this->y *= inverse;
	this->z *= inverse;
	this->w *= inverse;
	return *this;
}

float vector::Length( ) const
{
	return sqrt(
		Square( this->x ) +
		Square( this->y ) +
		Square( this->z ) +
		Square( this->w ) );
}

float vector::LengthSq( ) const
{
	return
		Square( this->x ) +
		Square( this->y ) +
		Square( this->z ) +
		Square( this->w );
}

void vector::ClampLength( const float & rhs )
{
	float length = LengthSq( );

	if( IsAboutZero( length ) )
	{
		return;
	}

	float scalar = rhs / sqrt( length );
	*this *= scalar;
}

void vector::Homogenize( )
{
	if( IsAboutZero( this->w ) )
	{
		return;
	}

	Normalize( );
	*this /= this->w;
}

void vector::Normalize( )
{
	float length = LengthSq( );

	if( IsAboutZero( length ) )
	{
		return;
	}

	*this /= sqrt( length );
}

bool ML::MATH::Vector::IsExact( const vector & lhs , const vector & rhs )
{
	return
		lhs.x == rhs.x &&
		lhs.y == rhs.y &&
		lhs.z == rhs.z &&
		lhs.w == rhs.w;
}

float ML::MATH::Vector::AngleBetween( const vector & lhs , const vector & rhs )
{
	float lengthLHS = lhs.LengthSq( );
	float lengthRHS = rhs.LengthSq( );

	if( IsAboutZero( lengthLHS ) || IsAboutZero( lengthRHS ) )
	{
		return 0.0f;
	}

	return acos( lhs * rhs / ( sqrt( lengthLHS ) * sqrt( lengthRHS ) ) );
}

float ML::MATH::Vector::Component( const vector& lhs , const vector& rhs )
{
	return lhs * Vector::Normalize( rhs );
}

float ML::MATH::Vector::DistanceBetween( const vector & lhs , const vector & rhs )
{
	return vector( lhs - rhs ).Length( );
}

std::ostream & ML::MATH::Vector::operator<<( std::ostream & os , const vector & rhs )
{
	os << "( "
		<< rhs.x << ", "
		<< rhs.y << ", "
		<< rhs.z << ", "
		<< rhs.w << " )";
	return os;
}

vector ML::MATH::Vector::Average( const vector & lhs , const vector & rhs )
{
	return vector(
		ML::MATH::Average( lhs.x , rhs.x ) ,
		ML::MATH::Average( lhs.y , rhs.y ) ,
		ML::MATH::Average( lhs.z , rhs.z ) ,
		ML::MATH::Average( lhs.w , rhs.w ) );
}

vector ML::MATH::Vector::Barycentric( const vector & lhs , const vector & rhs )
{
	vector bary = Cross( lhs , rhs );
	float inverseZ = 1.0f / bary.z;
	return vector( 1.0f - ( bary.x + bary.y ) * inverseZ , bary.y * inverseZ , bary.x * inverseZ );
}

vector ML::MATH::Vector::Clamp( const vector & rhs , const float& max )
{
	float length = rhs.LengthSq( );

	if( ML::MATH::IsAboutZero( length ) )
	{
		return rhs;
	}

	float scalar = max / sqrt( length );
	return vector( rhs * scalar );
}

vector ML::MATH::Vector::Cross( const vector& lhs , const vector& rhs )
{
	return vector(
		lhs.y * rhs.z - rhs.y * lhs.z ,
		rhs.x * lhs.z - lhs.x * rhs.z ,
		lhs.x * rhs.y - rhs.x * lhs.y ,
		1.0f );
}

vector ML::MATH::Vector::Homogenize( const vector & rhs )
{
	if( ML::MATH::IsAboutZero( rhs.w ) )
	{
		return vector( );
	}

	vector normalized = Normalize( rhs );
	return normalized / normalized.w;
}

vector ML::MATH::Vector::Lerp( const vector& lhs , const vector& rhs , const float t )
{
	return vector(
		ML::MATH::Lerp( lhs.x , rhs.x , t ) ,
		ML::MATH::Lerp( lhs.y , rhs.y , t ) ,
		ML::MATH::Lerp( lhs.z , rhs.z , t ) ,
		ML::MATH::Lerp( lhs.w , rhs.w , t ) );
}

vector ML::MATH::Vector::Max( const vector& lhs , const vector& rhs )
{
	return vector(
		ML::MATH::Greater( lhs.x , rhs.x ) ,
		ML::MATH::Greater( lhs.y , rhs.y ) ,
		ML::MATH::Greater( lhs.z , rhs.z ) ,
		ML::MATH::Greater( lhs.w , rhs.w ) );
}

vector ML::MATH::Vector::Min( const vector& lhs , const vector& rhs )
{
	return vector(
		ML::MATH::Lesser( lhs.x , rhs.x ) ,
		ML::MATH::Lesser( lhs.y , rhs.y ) ,
		ML::MATH::Lesser( lhs.z , rhs.z ) ,
		ML::MATH::Lesser( lhs.w , rhs.w ) );
}

vector ML::MATH::Vector::Normalize( const vector& rhs )
{
	float length = rhs.LengthSq( );

	if( ML::MATH::IsAboutZero( length ) )
	{
		return rhs;
	}

	return rhs / sqrt( length );
}

vector ML::MATH::Vector::Projection( const vector& lhs , const vector& rhs )
{
	float length = rhs.LengthSq( );

	if( ML::MATH::IsAboutZero( length ) )
	{
		return rhs * ( lhs * rhs );
	}

	vector norm_rhs( rhs / sqrt( length ) );
	return norm_rhs * ( lhs * norm_rhs );
}

vector ML::MATH::Vector::Reflection( const vector& lhs , const vector& rhs )
{
	float length = rhs.LengthSq( );

	if( ML::MATH::IsAboutZero( length ) )
	{
		return -lhs;
	}

	vector norm_rhs( rhs / sqrt( length ) );
	return ( norm_rhs * ( lhs * norm_rhs ) * 2 ) - lhs;
}
