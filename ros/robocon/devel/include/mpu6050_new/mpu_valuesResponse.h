// Generated by gencpp from file mpu6050_new/mpu_valuesResponse.msg
// DO NOT EDIT!


#ifndef MPU6050_NEW_MESSAGE_MPU_VALUESRESPONSE_H
#define MPU6050_NEW_MESSAGE_MPU_VALUESRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace mpu6050_new
{
template <class ContainerAllocator>
struct mpu_valuesResponse_
{
  typedef mpu_valuesResponse_<ContainerAllocator> Type;

  mpu_valuesResponse_()
    : ax(0.0)
    , ay(0.0)
    , az(0.0)  {
    }
  mpu_valuesResponse_(const ContainerAllocator& _alloc)
    : ax(0.0)
    , ay(0.0)
    , az(0.0)  {
  (void)_alloc;
    }



   typedef double _ax_type;
  _ax_type ax;

   typedef double _ay_type;
  _ay_type ay;

   typedef double _az_type;
  _az_type az;





  typedef boost::shared_ptr< ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator> const> ConstPtr;

}; // struct mpu_valuesResponse_

typedef ::mpu6050_new::mpu_valuesResponse_<std::allocator<void> > mpu_valuesResponse;

typedef boost::shared_ptr< ::mpu6050_new::mpu_valuesResponse > mpu_valuesResponsePtr;
typedef boost::shared_ptr< ::mpu6050_new::mpu_valuesResponse const> mpu_valuesResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace mpu6050_new

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'mpu6050_new': ['/home/suraj/robocon/src/mpu6050_new/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "271a8351f08a1993852d2e5e55f1efa1";
  }

  static const char* value(const ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x271a8351f08a1993ULL;
  static const uint64_t static_value2 = 0x852d2e5e55f1efa1ULL;
};

template<class ContainerAllocator>
struct DataType< ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mpu6050_new/mpu_valuesResponse";
  }

  static const char* value(const ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 ax\n"
"float64 ay\n"
"float64 az\n"
"\n"
;
  }

  static const char* value(const ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ax);
      stream.next(m.ay);
      stream.next(m.az);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct mpu_valuesResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mpu6050_new::mpu_valuesResponse_<ContainerAllocator>& v)
  {
    s << indent << "ax: ";
    Printer<double>::stream(s, indent + "  ", v.ax);
    s << indent << "ay: ";
    Printer<double>::stream(s, indent + "  ", v.ay);
    s << indent << "az: ";
    Printer<double>::stream(s, indent + "  ", v.az);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MPU6050_NEW_MESSAGE_MPU_VALUESRESPONSE_H
