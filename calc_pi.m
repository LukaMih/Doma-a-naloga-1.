N = 10000;

% Kličemo funkcijo mcc_pi
[znotraj, izven] = mcc_pi(N);

% Izračunamo vrednost π
[calculated_pi, error] = area_pi(length(znotraj), N);

% Izpis rezultatov
disp(['Izračunana vrednost π: ', num2str(calculated_pi)]);
disp(['Napaka: ', num2str(error)]);

circle = @(x) sqrt(1 - x.^2);

figure;
hold on;

% Točke znotraj in izven kroga
scatter(znotraj(:,1), znotraj(:,2), 'g.', 'MarkerEdgeAlpha',0.2);
scatter(izven(:,1), izven(:,2), 'r.', 'MarkerEdgeAlpha',0.2);

% Lok kroga
x_ = linspace(0, 1, 1000);
plot(x_, circle(x_), 'b', 'LineWidth', 2);

legend('Točke v krogu','Točke izven kroga','Krožnica');
title('Metoda Monte Carlo za iskanje približka števila pi');
xlabel('x');
ylabel('y');

function [pi_estimate, error] = area_pi(znotraj_count, total_count)
    pi_estimate = 4 * (znotraj_count / total_count);
    error = abs(pi - pi_estimate);
end
