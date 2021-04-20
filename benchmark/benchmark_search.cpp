//
// Created by Marcusfam on 20.04.2021.
//



const auto time_point_before_search = chrono::steady_clock::now();

if (input_file) {
while (line != "") {
getline(input_file, line);
if (line == "") {
break;
}
tree.Search(stoi(line));
}
}

const auto time_point_after_search = chrono::steady_clock::now();
const auto time_diff_search = time_point_after_search - time_point_before_search;
const auto time_elapsed_ns_search = chrono::duration_cast<chrono::nanoseconds>(time_diff_search).count();
cout << time_elapsed_ns_search << endl;