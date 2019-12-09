#include "Methods/Adam/AdamW.h"
//#include "Tools/Parameters.h"

IterationData AdamW(Function f, Vector startPoint, const StopCondition& stop_condition) {

  Real grad_accuracy = 0.00000001;
  //int iter_lim = 300;

  IterationData data;
  data.x_curr = startPoint;
  data.f_curr = f(startPoint);
  data.iter_counter = 0;

  Vector x_next;
  // Вектор-градиент и его покомпонентный квадрат
  Vector g, gd;

  Real f_next;
  // Сглаживающий коэффициент
  //Real e;for what?

  // Параметры сохранения моментов
  Real beta1, beta2;

  // Параметр метода
  Real gamma;

  // Первый и второй моменты
  Vector m, m_t, v, v_t;

  /* Присвоение соответствующих параметров из структуры параметров */

  beta1 = 0.86296943;//Adam_beta1 = 0.86296943;//0.9
  beta2 = 0.88791641;//Adam_beta2 = 0.88791641;//0.999
  gamma = 0.07670128;//Adam_gamma = 0.07670128;//0.00000001


  g = grad(f, data.x_curr, grad_accuracy);
  gd = g * g;
  m = (1 - beta1) * g;
  v = (1 - beta2) * gd;
  m_t = m * (1 / (1 - beta1));
  v_t = v * (1 / (1 - beta2));

  // Итеративная формула
  x_next = data.x_curr - gamma * (m_t / (sqrt(notNull(v_t)))+data.x_curr);
  f_next = f(x_next);

  //while (data.iter_counter < iter_lim || !stop_condition(data)) {
  //while (!stop_condition(data)) {
  do{  
    data.next(x_next, f_next);
    g = grad(f, data.x_curr, grad_accuracy);
    gd = g * g;
    m = beta1 * m + (1 - beta1) * g;
    v = beta2 * v + (1 - beta2) * gd;

    m_t = m * (1 / (1 - pow(beta1, data.iter_counter)));
    v_t = v * (1 / (1 - pow(beta2, data.iter_counter)));

    // Итеративная формула
    x_next = data.x_curr - gamma * (m_t / (sqrt(notNull(v_t)))+data.x_curr);
    f_next = f(x_next);
  }while (!stop_condition(data));

  return data;
}