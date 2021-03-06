/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef PY_FRONTEND_TCC_
#define PY_FRONTEND_TCC_

#include <thrift/compiler/py/compiler.h>

namespace thrift {
namespace compiler {
namespace py {

BOOST_PYTHON_MODULE(frontend) {
  def("process", process);

  // Expose some functions to the python scope
  scope().attr("dump_docstrings") = make_function(&dump_docstrings);

  /**
   * Exposing Types
   */

  // map<string, string> for t_type.annotations
  indexMap<string, string>("str_to_str_map");

  class_<std::vector<std::pair<t_const_value*, t_const_value*>>>(
      "const_to_const_map")
      .def("items", &map_item<t_const_value*, t_const_value*>().items);

  indexPtrVec<t_const_value>("t_const_value_vec");

  enum_<t_types::TypeValue>("TypeValue")
      .value("TYPE_VOID", t_type::TypeValue::TYPE_VOID)
      .value("TYPE_STRING", t_type::TypeValue::TYPE_STRING)
      .value("TYPE_BOOL", t_type::TypeValue::TYPE_BOOL)
      .value("TYPE_BYTE", t_type::TypeValue::TYPE_BYTE)
      .value("TYPE_I16", t_type::TypeValue::TYPE_I16)
      .value("TYPE_I32", t_type::TypeValue::TYPE_I32)
      .value("TYPE_I64", t_type::TypeValue::TYPE_I64)
      .value("TYPE_DOUBLE", t_type::TypeValue::TYPE_DOUBLE)
      .value("TYPE_ENUM", t_type::TypeValue::TYPE_ENUM)
      .value("TYPE_LIST", t_type::TypeValue::TYPE_LIST)
      .value("TYPE_SET", t_type::TypeValue::TYPE_SET)
      .value("TYPE_MAP", t_type::TypeValue::TYPE_MAP)
      .value("TYPE_STRUCT", t_type::TypeValue::TYPE_STRUCT)
      .value("TYPE_SERVICE", t_type::TypeValue::TYPE_SERVICE)
      .value("TYPE_PROGRAM", t_type::TypeValue::TYPE_PROGRAM)
      .value("TYPE_FLOAT", t_type::TypeValue::TYPE_FLOAT)
      .value("TYPE_STREAM", t_type::TypeValue::TYPE_STREAM);

  // t_type
  object ttype_class =
      class_<t_type, noncopyable>("t_type", no_init)
          .add_property("type_id", &t_type::get_type_id)
          .add_property("full_name", &t_type::get_full_name)
          .add_property("type_value", &t_type::get_type_value)
          .add_property(
              "name",
              make_function(&t_type::get_name, policy_ccr()),
              &t_type::set_name)
          .add_property(
              "program",
              make_function(
                  static_cast<const t_program* (t_type::*)() const>(
                      &t_type::get_program),
                  policy_reo()))
          .add_property("is_void", &t_type::is_void)
          .add_property("is_base_type", &t_type::is_base_type)
          .add_property("is_string", &t_type::is_string)
          .add_property("is_bool", &t_type::is_bool)
          .add_property("is_floating_point", &t_type::is_floating_point)
          .add_property("is_typedef", &t_type::is_typedef)
          .add_property("is_enum", &t_type::is_enum)
          .add_property("is_struct", &t_type::is_struct)
          .add_property("is_xception", &t_type::is_xception)
          .add_property("is_container", &t_type::is_container)
          .add_property("is_list", &t_type::is_list)
          .add_property("is_set", &t_type::is_set)
          .add_property("is_map", &t_type::is_map)
          .add_property("is_stream", &t_type::is_stream)
          .add_property("is_service", &t_type::is_service)
          .add_property("is_typedef", &t_type::is_typedef)
          .add_property("annotations", &t_type::annotations_)
          .add_property(
              "as_typedef", make_function(TO<t_typedef, t_type>, policy_rir()))
          .add_property(
              "as_base_type",
              make_function(TO<t_base_type, t_type>, policy_rir()))
          .add_property(
              "as_container",
              make_function(TO<t_container, t_type>, policy_rir()))
          .add_property(
              "as_map", make_function(TO<t_map, t_type>, policy_rir()))
          .add_property(
              "as_struct", make_function(TO<t_struct, t_type>, policy_rir()))
          .add_property(
              "as_set", make_function(TO<t_set, t_type>, policy_rir()))
          .add_property(
              "as_list", make_function(TO<t_list, t_type>, policy_rir()))
          .add_property(
              "as_stream", make_function(TO<t_stream, t_type>, policy_rir()))
          .add_property(
              "get_true_type",
              make_function(
                  static_cast<const t_type* (t_type::*)() const>(
                      &t_type::get_true_type),
                  policy_rir()));
  indexVec<uint8_t>("uint8_t_vec");

  // t_base_type::t_base
  enum_<t_base_type::t_base>("t_base")
      .value("void", t_base_type::TYPE_VOID)
      .value("string", t_base_type::TYPE_STRING)
      .value("bool", t_base_type::TYPE_BOOL)
      .value("byte", t_base_type::TYPE_BYTE)
      .value("i16", t_base_type::TYPE_I16)
      .value("i32", t_base_type::TYPE_I32)
      .value("i64", t_base_type::TYPE_I64)
      .value("double", t_base_type::TYPE_DOUBLE)
      .value("float", t_base_type::TYPE_FLOAT);

  // t_base_type
  class_<t_base_type, noncopyable, bases<t_type>>("t_base_type", no_init)
      .add_property("base", &t_base_type::get_base)
      // dunno if this should really be used, can rather extract the name
      // directly from the t_base object in python
      .add_static_property("t_base_name", &t_base_type::t_base_name)
      .add_property("is_binary", &t_base_type::is_binary);

  // t_container
  class_<t_container, noncopyable, bases<t_type>>("t_container", no_init);

  // t_map
  class_<t_map, noncopyable, bases<t_container>>("t_map", no_init)
      .add_property(
          "key_type", make_function(&t_map::get_key_type, policy_reo()))
      .add_property(
          "value_type", make_function(&t_map::get_val_type, policy_reo()))
      .add_property("is_unordered", &t_map::is_unordered);

  // t_set
  class_<t_set, noncopyable, bases<t_container>>("t_set", no_init)
      .add_property(
          "elem_type", make_function(&t_set::get_elem_type, policy_reo()))
      .add_property("is_unordered", &t_set::is_unordered);

  // t_list
  class_<t_list, noncopyable, bases<t_container>>("t_list", no_init)
      .add_property(
          "elem_type", make_function(&t_list::get_elem_type, policy_reo()));

  // t_stream
  class_<t_stream, noncopyable, bases<t_type>>("t_stream", no_init)
      .add_property(
          "elem_type", make_function(&t_stream::get_elem_type, policy_reo()));

  // t_field::e_req
  enum_<t_field::e_req>("e_req")
      .value("required", t_field::T_REQUIRED)
      .value("optional", t_field::T_OPTIONAL)
      .value("opt_in_req_out", t_field::T_OPT_IN_REQ_OUT);

  // t_field
  class_<t_field, noncopyable>("t_field", init<t_type*, std::string>())
      .def(init<t_type*, std::string, int32_t>())
      .add_property("type", make_function(&t_field::get_type, policy_reo()))
      .add_property("name", make_function(&t_field::get_name, policy_ccr()))
      .add_property(
          "value",
          make_function(
              static_cast<const t_const_value* (t_field::*)() const>(
                  &t_field::get_value),
              policy_reo()))
      .def_readonly("annotations", &t_field::annotations_)
      .add_property("key", &t_field::get_key)
      .add_property("req", &t_field::get_req);
  indexPtrVec<t_field>("t_field_vec");

  // t_struct
  class_<t_struct, noncopyable, bases<t_type>>(
      "t_struct", init<t_program*, const string&>())
      .add_property(
          "members", make_function(&t_struct::get_members, policy_reo()))
      .add_property("is_union", &t_struct::is_union);
  indexPtrVec<t_struct>("t_struct_vec");

  // t_typedef
  class_<t_typedef, noncopyable, bases<t_type>>("t_typedef", no_init)
      .add_property("type", make_function(&t_typedef::get_type, policy_rir()))
      .add_property(
          "symbolic", make_function(&t_typedef::get_symbolic, policy_ccr()));
  indexPtrVec<t_typedef>("t_typedef_vec");

  // t_scope
  class_<t_scope, noncopyable>("t_scope", no_init);

  // t_enum_value
  // TODO bases<t_doc>
  class_<t_enum_value, noncopyable>("t_enum_value", no_init)
      .add_property(
          "name", make_function(&t_enum_value::get_name, policy_ccr()))
      .add_property("value", &t_enum_value::get_value)
      .def_readonly("annotations", &t_enum_value::annotations_);
  indexPtrVec<t_enum_value>("t_enum_value_vec");

  // t_enum
  class_<t_enum, noncopyable, bases<t_type>>("t_enum", no_init)
      .def("find_value", &t_enum::find_value, policy_rir())
      .add_property(
          "enum_values", make_function(&t_enum::get_enum_values, policy_rir()));
  indexPtrVec<t_enum>("t_enum_vec");

  // t_const
  class_<t_const, noncopyable>("t_const", no_init)
      .add_property("type", make_function(&t_const::get_type, policy_reo()))
      .add_property("name", &t_const::get_name)
      .add_property("value", make_function(&t_const::get_value, policy_reo()))
      .add_property(
          "program", make_function(&t_const::get_program, policy_reo()))
      .def("__eq__", &t_const_operatorEq)
      .def("__ne__", &t_const_operatorNe);
  indexPtrVec<t_const>("t_const_vec");

  // t_const_value::t_const_value_type
  enum_<t_const_value::t_const_value_type>("e_const_value_type")
      .value("integer", t_const_value::CV_INTEGER)
      .value("double", t_const_value::CV_DOUBLE)
      .value("string", t_const_value::CV_STRING)
      .value("map", t_const_value::CV_MAP)
      .value("list", t_const_value::CV_LIST);

  // t_const_value
  class_<t_const_value, noncopyable>("t_const_value", no_init)
      .add_property(
          "string", make_function(&t_const_value::get_string, policy_ccr()))
      .add_property("double", &t_const_value::get_double)
      .add_property("integer", &t_const_value::get_integer)
      .add_property("map", make_function(&t_const_value::get_map, policy_rir()))
      .add_property(
          "list", make_function(&t_const_value::get_list, policy_rir()))
      .add_property(
          "owner", make_function(&t_const_value::get_owner, policy_reo()))
      .add_property("type", &t_const_value::get_type)
      // get_type ... need to define the t_const_value::t_const_value_type enum
      ;

  // t_function
  class_<t_function, noncopyable>("t_function", no_init)
      .add_property("name", make_function(&t_function::get_name, policy_ccr()))
      .add_property(
          "arglist", make_function(&t_function::get_arglist, policy_rir()))
      .add_property("oneway", make_function(&t_function::is_oneway))
      .add_property(
          "returntype",
          make_function(&t_function::get_returntype, policy_rir()))
      .add_property(
          "xceptions", make_function(&t_function::get_xceptions, policy_rir()))
      .add_property(
          "annotations",
          make_function(&t_function::get_annotations, policy_rir()));

  indexPtrVec<t_function>("t_function_vec");

  // t_service
  class_<t_service, noncopyable, bases<t_type>>("t_service", no_init)
      .add_property(
          "extends", make_function(&t_service::get_extends, policy_rir()))
      .add_property(
          "functions", make_function(&t_service::get_functions, policy_rir()));

  indexPtrVec<t_service>("t_service_vec");

  class_<t_program, noncopyable>("t_program", no_init)
      .add_property("path", make_function(&t_program::get_path, policy_ccr()))
      .add_property("name", make_function(&t_program::get_name, policy_ccr()))
      .add_property(
          "namespace",
          make_function(
              static_cast<const string& (t_program::*)() const>(
                  &t_program::get_namespace),
              policy_ccr()),
          static_cast<void (t_program::*)(string)>(&t_program::set_namespace))
      .def(
          "get_namespace",
          make_function(
              static_cast<const string& (t_program::*)(const string&)const>(
                  &t_program::get_namespace),
              policy_ccr()))
      .add_property(
          "namespaces", make_function(&t_program::get_namespaces, policy_rir()))
      .add_property(
          "include_prefix",
          make_function(&t_program::get_include_prefix, policy_ccr()),
          &t_program::set_include_prefix)
      .add_property(
          "typedefs", make_function(&t_program::get_typedefs, policy_rir()))
      .add_property("enums", make_function(&t_program::get_enums, policy_rir()))
      .add_property(
          "consts", make_function(&t_program::get_consts, policy_rir()))
      .add_property(
          "structs", make_function(&t_program::get_structs, policy_rir()))
      .add_property(
          "exceptions", make_function(&t_program::get_xceptions, policy_rir()))
      .add_property(
          "objects", make_function(&t_program::get_objects, policy_rir()))
      .add_property(
          "services", make_function(&t_program::get_services, policy_rir()))
      .add_property(
          "includes",
          make_function(&t_program::get_included_programs, policy_rbv()))
      .add_property(
          "cpp_includes",
          make_function(&t_program::get_cpp_includes, policy_rir()))
      // WARNING: returned t_scope* is unowned. Shouldn't be a problem in
      // this case though. Alternatively use manage_new_object
      .add_property("scope", make_function(&t_program::scope, policy_reo()))
      .def("__eq__", &t_program_operatorEq)
      .def("__ne__", &t_program_operatorNe);
  indexPtrVec<t_program>("t_program_vec");
  // Register a string vector as a python class
  class_<vector<std::string>>("string_vec")
      .def(vector_indexing_suite<vector<std::string>>());
}

} // namespace py
} // namespace compiler
} // namespace thrift

#endif
