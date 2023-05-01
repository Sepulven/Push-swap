/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:29:23 by asepulve          #+#    #+#             */
/*   Updated: 2023/05/02 00:28:01 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_sub_stack(t_list **a, t_list **b, t_sort_n stat)
{
	int		pos;
	int		r_a_tip;

	r_a_tip = 0;
	while (stat.l_side + stat.r_side > 1 && stat.size)
	{
		pos = best_el(*b, stat.l_side, stat.r_side, &stat);
		send_el_to(a, b, pos, 'a');
		calc_tips_size(&stat, pos);
		checker(a, b, &stat, &r_a_tip);
	}
	pa(a, b);
	while (r_a_tip-- > 0)
		rra(a);
}

static void	init_stacks_size(int *a, int*b, int size)
{
	a[0] = size / 2;
	b[0] = size / 2 + (size % 2 != 0);
	a[1] = a[0] / 2;
	b[1] = b[0] / 2;
	a[2] = a[1] / 2;
	b[2] = b[1] / 2;
}

//  * No momento de dar o split eu posso simplemente passa um elemento para um lado e deixo o outro.
//  * So tenho de ter cuidado para perder o el.
void	push_swap(t_list **a, t_list **b, int size)
{
	int	i;
	int	stack_a[3];
	int	stack_b[3];

	init_stacks_size(stack_a, stack_b, size);
	split_stack_diviser(a, b, (t_stat){'a', 'c', size});
	diviser_tips(a, b, (t_stat){'a', 'c', stack_b[1]});
	diviser_tips(a, b, (t_stat){'a', 'c', stack_b[1] + (stack_b[0] % 2 != 0)});
	diviser_tips(a, b, (t_stat){'b', 'd', stack_b[2]});
	i = 0;
	while (i++ < stack_b[2] + (stack_b[1] % 2 != 0))
		rra(a);
	diviser_tips(a, b, (t_stat){'b', 'd', stack_b[2] + (stack_b[1] % 2 != 0)});
	diviser_tips(a, b, (t_stat){'b', 'd', stack_b[2]});
	i = 0;
	while (i++ < stack_b[2] + (stack_b[1] % 2 != 0))
		rra(a);
	diviser_tips(a, b, (t_stat){'b', 'd', stack_b[2] + (stack_b[1] % 2 != 0)});
	split_stack_diviser(a, b, (t_stat){'a', 'c', stack_a[0] + (size % 2 != 0)});
	diviser_tips_sorted(a, b, (t_stat){'b', 'c', stack_a[1] + (stack_a[0] % 2 != 0)});
	sort_sub_stack(a, b, (t_sort_n){size, 0,\
	'b', 'g', ft_lstsize(*b)});
}

// diviser_tips_sorted(a, b, (t_stat){'b', 'c', size / 2});

	// sort_sub_stack(a, b, (t_sort_n){size / 2, size / 2, 
	// 'b', 'g', ft_lstsize(*b)});

/*
	! 222 340 52 432 227 145 221 289 92 163 242 433 449 108 302 199 158 161 55 472 285 48 445 291 458 292 438 94 117 37 479 132 489 367 398 431 193 424 452 149 58 483 274 466 195 440 387 380 34 155 237 187 9 160 415 142 321 19 229 25 234 499 338 166 63 198 202 35 485 496 232 20 408 148 267 175 410 244 436 375 106 259 42 215 255 451 462 141 301 82 269 384 207 284 7 381 130 233 54 26 156 235 426 205 468 71 79 342 135 418 403 40 265 214 330 353 497 120 250 101 13 57 10 281 23 217 78 47 385 272 69 328 223 152 400 21 185 228 271 50 430 311 247 22 188 288 491 336 463 377 61 239 475 357 240 372 177 280 28 275 495 355 218 500 134 192 18 354 409 147 76 38 179 62 349 362 490 45 129 51 406 439 125 420 394 256 350 407 402 379 339 81 93 138 266 494 36 467 435 104 168 416 334 332 133 264 91 115 89 5 66 209 151 165 365 477 59 457 189 442 196 391 157 216 73 392 118 344 252 455 304 444 286 465 370 331 203 294 67 39 473 448 314 164 113 191 450 201 422 116 484 309 454 102 248 30 111 295 72 6 182 326 395 373 296 322 127 364 64 180 459 305 70 212 260 24 8 419 263 293 65 211 469 374 83 137 383 253 437 183 238 230 122 85 290 254 121 178 243 197 200 376 404 110 246 109 329 399 347 317 46 88 434 306 411 105 4 273 96 169 423 119 414 316 144 194 389 471 447 319 95 249 312 31 270 172 208 401 77 53 245 276 68 480 98 128 174 112 356 167 351 453 44 324 278 369 33 358 461 421 43 441 303 123 27 224 268 12 15 315 361 190 493 170 176 313 226 352 425 476 99 220 428 282 124 359 204 460 213 206 49 366 487 310 126 308 279 87 371 283 287 397 97 251 443 171 382 429 159 318 86 478 210 412 56 154 307 84 131 231 345 114 150 262 488 219 368 320 153 90 446 378 299 337 41 413 1 140 360 297 60 14 482 181 486 396 335 390 184 348 393 162 29 186 427 241 386 346 173 103 388 261 341 143 325 277 456 481 100 474 236 258 498 16 3 139 146 2 343 74 80 17 417 323 464 327 300 75 333 298 11 405 225 363 492 470 136 107 257 32 
	! 442 167 227 158 323 79 125 449 121 233 96 469 407 126 93 294 303 247 240 71 265 70 177 66 238 169 470 151 384 328 56 97 115 387 170 337 213 3 203 369 101 494 412 194 491 184 309 297 340 48 235 147 7 128 482 77 37 186 137 76 260 165 92 438 324 334 290 55 493 95 174 454 124 16 326 63 23 185 386 225 286 261 136 24 190 113 467 207 219 300 363 435 212 30 226 403 497 472 173 110 162 391 139 200 65 444 440 360 187 458 264 152 305 476 144 345 385 436 47 439 499 175 274 104 19 329 381 189 214 456 375 105 465 279 129 88 90 420 2 473 202 107 275 40 361 292 401 299 231 150 448 209 377 236 277 130 462 223 45 421 364 118 289 242 406 164 397 171 352 20 161 259 365 21 331 283 333 308 432 87 111 408 241 411 198 153 178 44 143 314 392 228 94 310 424 344 43 69 22 478 193 157 211 221 145 445 362 481 14 374 343 27 100 251 199 398 4 81 452 426 409 230 254 106 18 390 108 315 222 112 148 31 98 417 268 188 239 320 460 441 156 282 33 206 500 451 116 135 11 6 471 168 330 293 114 204 117 347 246 46 422 49 388 359 244 350 138 52 163 298 342 490 229 307 371 232 123 339 321 466 176 10 25 416 26 1 498 54 9 122 475 248 50 455 210 414 487 457 252 166 285 336 322 42 234 447 172 146 468 127 120 484 89 34 183 180 41 154 36 296 224 379 489 495 405 35 13 346 182 325 383 492 483 437 109 132 201 429 245 28 477 319 291 380 474 72 427 353 302 332 433 461 85 102 485 356 15 357 418 273 419 51 216 160 450 197 62 378 218 395 295 355 373 142 266 338 256 316 250 220 281 255 486 327 376 29 258 84 351 208 488 366 5 38 317 39 382 17 262 425 263 134 280 32 430 496 141 257 73 67 196 217 480 404 253 133 304 75 431 358 270 68 249 91 413 83 12 215 443 271 119 434 428 269 103 349 53 78 57 306 453 82 318 272 389 131 80 278 410 312 74 159 237 267 313 423 205 287 61 64 459 149 99 402 399 446 59 191 58 155 86 341 192 335 372 179 464 370 195 311 348 396 301 60 415 367 288 463 479 368 394 181 400 140 393 354 276 284 243 8 
	! 120 18 52 275 167 333 379 243 108 236 448 10 142 292 203 182 271 219 304 65 430 343 320 354 399 215 478 272 140 446 34 171 483 418 262 138 39 194 279 242 100 496 346 92 97 317 481 464 288 198 96 466 386 451 282 44 499 127 415 264 25 441 22 337 432 218 249 409 396 58 437 442 66 270 420 56 69 53 197 421 73 36 494 231 495 255 376 76 291 455 296 155 284 479 314 294 173 395 13 14 474 55 162 147 263 417 359 95 384 193 102 473 361 113 29 199 112 289 378 184 3 471 349 330 277 307 321 118 482 332 363 196 168 486 326 413 258 274 72 463 305 406 89 99 220 93 425 79 310 17 315 221 265 429 151 45 149 195 401 468 453 90 273 8 228 444 42 60 117 110 462 472 137 440 253 388 422 500 476 41 75 86 452 411 375 148 176 269 63 350 12 447 250 344 268 389 419 436 410 31 230 40 225 64 206 370 400 125 129 398 16 213 248 427 80 484 126 200 467 139 226 2 373 303 234 480 216 340 334 161 154 4 156 424 328 82 37 299 374 261 404 87 434 158 316 391 141 48 164 465 211 165 27 454 280 339 259 143 94 392 267 181 185 416 342 377 35 329 460 300 369 445 169 239 224 188 189 98 251 423 403 91 217 338 457 290 159 107 212 380 244 111 67 20 26 278 15 223 68 170 489 132 325 24 59 70 144 130 498 309 5 232 323 319 152 51 276 426 355 348 252 11 191 266 160 54 71 21 46 493 30 57 241 166 311 345 101 19 433 366 293 201 475 301 124 47 109 81 114 32 381 233 487 115 341 105 49 402 85 469 497 318 302 134 119 285 74 306 412 390 365 84 324 106 356 260 362 351 461 383 360 190 205 397 247 175 298 116 229 394 450 153 382 210 331 313 372 456 7 336 135 286 204 256 150 352 347 459 414 458 122 77 157 183 364 435 104 358 146 357 490 43 179 488 470 335 443 407 136 222 78 405 33 214 438 9 385 145 131 88 103 297 1 50 439 178 287 192 186 121 61 202 431 295 322 477 207 128 368 281 245 133 283 38 174 123 428 28 240 254 238 491 449 353 257 485 172 83 492 387 62 6 371 177 408 246 23 163 367 227 393 327 180 187 208 237 312 308 235 209 
	! 220 133 81 338 102 493 273 336 215 175 367 409 240 301 183 189 283 198 421 148 447 490 463 311 428 424 251 21 340 241 173 355 415 329 202 293 453 129 307 157 94 32 141 462 36 49 142 412 351 193 174 246 467 496 364 166 85 361 337 397 264 227 281 4 422 221 382 333 63 185 200 24 136 28 354 482 267 369 433 219 82 394 178 258 327 492 436 51 52 77 125 358 344 322 206 96 401 23 275 203 310 34 46 451 442 180 87 139 386 403 383 489 207 146 389 460 237 20 137 289 385 484 406 456 170 38 104 247 390 269 398 330 64 480 261 271 194 191 164 441 192 17 455 231 39 339 362 222 213 70 345 404 217 131 228 459 210 341 454 488 254 41 377 334 99 466 464 9 305 226 296 187 332 443 95 107 294 54 259 74 471 118 11 370 431 324 357 143 244 368 65 461 477 363 395 152 165 434 446 452 31 257 37 153 128 115 468 410 457 127 352 374 479 418 109 135 160 140 93 212 147 33 494 14 119 365 12 182 245 243 110 387 162 249 381 265 19 121 232 92 437 61 79 270 500 58 314 117 308 27 498 75 233 427 216 325 48 204 252 218 80 7 57 172 197 306 154 486 473 399 445 84 491 285 124 234 417 313 196 342 277 86 393 167 103 426 291 5 375 323 56 348 481 73 235 499 225 449 229 478 250 91 438 268 379 98 448 188 90 331 378 328 126 155 76 423 309 122 68 317 356 78 181 298 97 260 429 236 279 43 130 292 145 372 469 214 224 120 286 465 321 72 303 111 177 67 66 425 132 320 299 408 190 495 475 420 388 211 373 123 280 402 472 138 350 371 13 150 83 391 366 201 343 42 171 101 413 274 159 238 376 239 112 195 347 62 474 100 45 242 114 407 497 59 384 248 392 161 89 209 26 105 253 255 300 416 353 184 435 444 450 179 69 312 60 71 439 40 15 419 476 106 288 440 88 158 487 485 149 16 2 163 335 360 35 396 405 263 282 230 349 458 483 262 411 18 319 151 470 199 359 156 22 316 186 144 47 295 168 346 400 290 134 256 266 318 304 176 315 326 414 8 1 302 10 276 3 25 297 53 432 287 208 55 284 113 29 223 50 44 272 169 30 108 6 116 205 278 380 430 
	! 223 423 88 10 500 376 136 339 464 239 484 184 145 352 453 477 469 154 195 446 27 92 465 388 25 80 287 396 459 207 309 421 30 172 415 226 101 413 407 329 114 307 479 123 110 404 411 259 454 153 146 219 156 410 241 487 93 97 90 264 52 260 236 350 17 83 366 437 66 252 41 45 19 451 43 173 174 211 262 40 297 205 276 499 372 72 117 37 318 436 472 109 132 147 286 21 321 394 374 473 391 398 357 344 53 142 445 85 381 369 139 129 400 345 128 250 395 178 233 330 238 91 375 491 112 167 485 64 140 44 217 266 229 48 56 82 461 68 353 279 457 251 32 409 427 364 29 36 127 170 468 246 18 188 268 59 149 428 483 231 221 155 333 458 476 470 213 312 278 349 47 242 290 280 418 159 434 131 311 475 181 157 63 378 403 393 108 405 298 385 245 175 35 111 119 482 124 406 342 460 254 12 440 343 89 200 198 497 489 335 116 158 24 102 271 209 332 253 324 462 160 363 38 199 189 302 134 234 196 220 442 165 294 204 347 346 179 361 358 180 319 2 293 492 283 130 397 486 77 326 148 313 215 274 431 34 74 23 336 137 230 162 191 218 303 359 214 322 33 232 100 8 94 351 248 95 249 382 334 291 120 377 463 340 282 325 399 402 16 430 456 444 192 450 7 4 9 386 3 331 380 467 435 490 5 185 133 164 203 417 98 426 121 105 348 466 420 87 478 71 275 61 190 46 14 448 113 496 338 141 368 305 370 256 289 389 138 443 11 144 103 304 273 257 272 67 337 452 125 258 99 26 20 62 163 107 57 362 449 49 210 306 115 295 429 86 416 310 317 193 177 39 356 201 480 447 481 373 81 247 392 323 360 367 202 168 355 65 6 296 208 1 60 438 299 166 194 267 150 135 255 118 106 495 316 441 488 414 425 383 494 244 240 69 151 104 227 235 182 143 70 31 424 222 365 261 354 96 186 493 284 78 126 228 285 327 55 58 28 320 197 51 13 384 183 328 75 176 419 433 408 371 212 79 277 265 341 187 152 471 161 15 387 269 401 455 224 263 300 225 50 84 288 270 206 314 237 122 42 390 292 474 422 54 498 22 73 301 439 243 315 308 216 76 281 169 379 432 412 171 
*/
int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		lst_size;
	int		i;

	a = NULL;
	b = NULL;
	(void)lst_size;
	(void)i;
	(void)b;
	if (!validator(argc, argv))
		return (write(2, "Error1\n", 7));
	a = converter(argc, argv);
	if (!a)
		return (write(2, "Error2\n", 7));
	if (argc - 1 < 50)
		sort_n_own_stack(&a, &b);
	else
		push_swap(&a, &b, argc - 1);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
