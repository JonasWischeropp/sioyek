#pragma once

#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include "sqlite3.h"
#include "book.h"
#include "utils.h"

bool create_opened_books_table(sqlite3* db);
bool create_marks_table(sqlite3* db);
bool select_opened_book(sqlite3* db, const std::wstring& book_path, std::vector<OpenedBookState>& out_result);
bool insert_mark(sqlite3* db, const std::string& checksum, char symbol, float offset_y);
bool update_mark(sqlite3* db, const std::string& checksum, char symbol, float offset_y);
bool update_book(sqlite3* db, const std::wstring& path, float zoom_level, float offset_x, float offset_y);
bool select_mark(sqlite3* db, const std::string& checksum, std::vector<Mark>& out_result);
bool create_bookmarks_table(sqlite3* db);
bool insert_bookmark(sqlite3* db, const std::string& checksum, const std::wstring& desc, float offset_y);
bool select_bookmark(sqlite3* db, const std::string& checksum, std::vector<BookMark>& out_result);
bool create_links_table(sqlite3* db);
bool insert_link(sqlite3* db, const std::string& src_checksum, const std::string& dst_checksum, float dst_offset_y, float dst_offset_x, float dst_zoom_level, float src_offset_y);
bool select_links(sqlite3* db, const std::string& src_checksum, std::vector<Link>& out_result);
bool delete_link(sqlite3* db, const std::string& src_checksum, float src_offset_y);
bool delete_bookmark(sqlite3* db, const std::string& src_checksum, float src_offset_y);
bool global_select_bookmark(sqlite3* db,  std::vector<std::pair<std::string, BookMark>>& out_result);
bool global_select_highlight(sqlite3* db, std::vector<std::pair<std::string, Highlight>>& out_result);
bool update_link(sqlite3* db, const std::string& checksum, float dst_offset_x, float dst_offset_y, float dst_zoom_level, float src_offset_y);
bool select_prev_docs(sqlite3* db,  std::vector<std::wstring>& out_result);
void create_tables(sqlite3* db);
bool delete_mark_with_symbol(sqlite3* db, char symbol);
bool select_global_mark(sqlite3* db, char symbol, std::vector<std::pair<std::string, float>>& out_result);
bool delete_opened_book(sqlite3* db, const std::wstring& book_path);
bool create_highlights_table(sqlite3* db);
bool delete_highlight(sqlite3* db, const std::string& checksum, float begin_x, float begin_y, float end_x, float end_y);
bool select_highlight(sqlite3* db, const std::string& checksum, std::vector<Highlight>& out_result);
bool select_highlight_with_type(sqlite3* db, const std::string& checksum, char type, std::vector<Highlight>& out_result);
bool insert_highlight(sqlite3* db,
	const std::string& checksum,
	const std::wstring& desc,
	float begin_x,
	float begin_y,
	float end_x,
	float end_y,
	char type);

bool get_path_from_hash(sqlite3* db, const std::string& checksum, std::vector<std::wstring>& out_paths);
bool get_hash_from_path(sqlite3* db, const std::string& path, std::vector<std::wstring>& out_checksum);
bool get_prev_path_hash_pairs(sqlite3* db, std::vector<std::pair<std::wstring, std::wstring>>& out_pairs);
bool insert_document_hash(sqlite3* db, const std::wstring& path, const std::string& checksum);
bool update_mark_path(sqlite3* db, const std::wstring& path, const std::wstring& new_path);
void upgrade_database_hashes(sqlite3* db);
