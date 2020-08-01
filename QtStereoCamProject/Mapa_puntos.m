file = fopen('xyz.txt');
X = [];
Y = [];
Z = [];
temp = textscan(file, '%f %f %f');

X(:,1) = cell2mat(temp(1));
Y(:,1) = cell2mat(temp(2));
Z(:,1) = cell2mat(temp(3));

%scatter3(X, Y, Z, '.');
%view(0,-90)

P = [X Y Z];

num = size(X, 1);
C = 200.*ones(num, 3);
header = 'ply\n';
header = [header, 'format ascii 1.0\n'];
header = [header, 'comment written by Alvaro\n'];
header = [header, 'element vertex ', num2str(num), '\n'];
header = [header, 'property float32 x\n'];
header = [header, 'property float32 y\n'];
header = [header, 'property float32 z\n'];
header = [header, 'property uchar red\n'];
header = [header, 'property uchar green\n'];
header = [header, 'property uchar blue\n'];
header = [header, 'end_header\n'];

data = [P double(C)];
fname = 'xyz.ply';

fid = fopen(fname, 'w');
fprintf(fid, header);
dlmwrite(fname, data, '-append', 'delimiter', '\t', 'precision', 3);
fclose(fid);