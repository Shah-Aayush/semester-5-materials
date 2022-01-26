import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

class Category {
  final int categoryId;
  final String name;
  final IconData icon;

  Category({this.categoryId, this.name, this.icon});
}

final allCategory = Category(
  categoryId: 0,
  name: "All",
  icon: Icons.search,
);

final musicCategory = Category(
  categoryId: 1,
  name: "Coding",
  icon: Icons.code,
);

final meetUpCategory = Category(
  categoryId: 2,
  name: "Sports",
  icon: Icons.sports_baseball,
);

final golfCategory = Category(
  categoryId: 3,
  name: "Music",
  icon: Icons.music_note,
);

final birthdayCategory = Category(
  categoryId: 4,
  name: "Parties",
  icon: Icons.fastfood,
);

final categories = [
  allCategory,
  musicCategory,
  meetUpCategory,
  golfCategory,
  birthdayCategory,
];
