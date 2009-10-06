#ifndef MATERIALFACTORY_H
#define MATERIALFACTORY_H

#include <string>
#include <map>


class Material;


class MaterialFactory {
  friend class Material;

  typedef std::multimap< std::string , Material *> MaterialMap;
  MaterialMap map_;

  static MaterialFactory* instance_;
  static MaterialFactory& instance();

  static void add_material(Material *material);
  static void remove_material(Material *material);
public:
  static Material* get_material(const std::string& name);
  static Material* get_random_material();
  static void print_materials();
};

#endif // MATERIALFACTORY_H
