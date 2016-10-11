[DC, map] = imread("dc.png");
DC = double(ind2rgb(DC,map));
DC = 1 .- DC;
DC_size = size(DC);

DC_row = reshape(DC, [], 3).';

colours = [0, 0, 0;
           111, 156, 101;
           0, 0, 510];

colours = colours';
colours = (255 .- colours) ./ 255;

colours2 = [0, 0, 0;
           199, 199, 160;
           0, 510, 0];

colours2 = colours2';
colours2 = (255 .- colours2) ./ 255;

PROJ13 = [1, 0, 0;
          0, 0, 0;
          0, 0, 1];

combined_matrix1 = colours * PROJ13 * inv(colours);
combined_matrix2 = colours2 * PROJ13 * inv(colours2);

combined_matrix = combined_matrix2 * combined_matrix1;

new_row = combined_matrix * DC_row;

new_image = reshape(new_row.', DC_size);
new_image = 1 .- new_image;

imwrite(new_image, "altered_dc.png");
