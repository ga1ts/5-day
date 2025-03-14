
Critical errors
---------------
No critical errors, all files were checked.
Important: Analysis is still not guaranteed to be 'complete' it is possible there are false negatives.


Open source checkers
--------------------
Yes  Check64BitPortability::pointerassignment
Yes  CheckAssert::assertWithSideEffects
Yes  CheckAutoVariables::assignFunctionArg
Yes  CheckAutoVariables::autoVariables
Yes  CheckAutoVariables::checkVarLifetime
No   CheckBool::checkAssignBoolToFloat                         require:style,c++
Yes  CheckBool::checkAssignBoolToPointer
No   CheckBool::checkBitwiseOnBoolean                          require:style,inconclusive
Yes  CheckBool::checkComparisonOfBoolExpressionWithInt
No   CheckBool::checkComparisonOfBoolWithBool                  require:style,c++
No   CheckBool::checkComparisonOfBoolWithInt                   require:warning,c++
No   CheckBool::checkComparisonOfFuncReturningBool             require:style,c++
Yes  CheckBool::checkIncrementBoolean
Yes  CheckBool::pointerArithBool
Yes  CheckBool::returnValueOfFunctionReturningBool
No   CheckBoost::checkBoostForeachModification
Yes  CheckBufferOverrun::analyseWholeProgram
Yes  CheckBufferOverrun::argumentSize
Yes  CheckBufferOverrun::arrayIndex
Yes  CheckBufferOverrun::arrayIndexThenCheck
Yes  CheckBufferOverrun::bufferOverflow
Yes  CheckBufferOverrun::negativeArraySize
Yes  CheckBufferOverrun::objectIndex
Yes  CheckBufferOverrun::pointerArithmetic
No   CheckBufferOverrun::stringNotZeroTerminated               require:warning,inconclusive
Yes  CheckClass::analyseWholeProgram
No   CheckClass::checkConst                                    require:style,inconclusive
No   CheckClass::checkConstructors                             require:style,warning
No   CheckClass::checkCopyConstructors                         require:warning
No   CheckClass::checkDuplInheritedMembers                     require:warning
No   CheckClass::checkExplicitConstructors                     require:style
No   CheckClass::checkMemset
No   CheckClass::checkMissingOverride                          require:style,c++03
No   CheckClass::checkSelfInitialization
No   CheckClass::checkThisUseAfterFree                         require:warning
No   CheckClass::checkUnsafeClassRefMember                     require:warning,safeChecks
No   CheckClass::checkUselessOverride                          require:style
No   CheckClass::checkVirtualFunctionCallInConstructor         require:warning
No   CheckClass::initializationListUsage                       require:performance
No   CheckClass::initializerListOrder                          require:style,inconclusive
No   CheckClass::operatorEqRetRefThis                          require:style
No   CheckClass::operatorEqToSelf                              require:warning
No   CheckClass::privateFunctions                              require:style
No   CheckClass::thisSubtraction                               require:warning
No   CheckClass::virtualDestructor
Yes  CheckCondition::alwaysTrueFalse
Yes  CheckCondition::assignIf
Yes  CheckCondition::checkAssignmentInCondition
Yes  CheckCondition::checkBadBitmaskCheck
No   CheckCondition::checkCompareValueOutOfTypeRange           require:style,platform
Yes  CheckCondition::checkDuplicateConditionalAssign
Yes  CheckCondition::checkIncorrectLogicOperator
Yes  CheckCondition::checkInvalidTestForOverflow
Yes  CheckCondition::checkModuloAlwaysTrueFalse
Yes  CheckCondition::checkPointerAdditionResultNotNull
Yes  CheckCondition::clarifyCondition
Yes  CheckCondition::comparison
Yes  CheckCondition::duplicateCondition
Yes  CheckCondition::multiCondition
Yes  CheckCondition::multiCondition2
No   CheckExceptionSafety::checkCatchExceptionByValue          require:style
No   CheckExceptionSafety::checkRethrowCopy                    require:style
No   CheckExceptionSafety::deallocThrow                        require:warning
No   CheckExceptionSafety::destructors                         require:warning
No   CheckExceptionSafety::nothrowThrows
No   CheckExceptionSafety::rethrowNoCurrentException
No   CheckExceptionSafety::unhandledExceptionSpecification     require:style,inconclusive
Yes  CheckFunctions::checkIgnoredReturnValue
Yes  CheckFunctions::checkMathFunctions
Yes  CheckFunctions::checkMissingReturn
Yes  CheckFunctions::checkProhibitedFunctions
Yes  CheckFunctions::invalidFunctionUsage
Yes  CheckFunctions::memsetInvalid2ndParam
Yes  CheckFunctions::memsetZeroBytes
No   CheckFunctions::returnLocalStdMove                        require:performance,c++11
Yes  CheckFunctions::useStandardLibrary
No   CheckIO::checkCoutCerrMisusage                            require:c
Yes  CheckIO::checkFileUsage
Yes  CheckIO::checkWrongPrintfScanfArguments
Yes  CheckLeakAutoVar::check
No   CheckMemoryLeakInClass::check
Yes  CheckMemoryLeakInFunction::checkReallocUsage
Yes  CheckMemoryLeakNoVar::check
Yes  CheckMemoryLeakStructMember::check
Yes  CheckNullPointer::analyseWholeProgram
Yes  CheckNullPointer::arithmetic
Yes  CheckNullPointer::nullConstantDereference
Yes  CheckNullPointer::nullPointer
No   CheckOther::checkAccessOfMovedVariable                    require:c++11,warning
Yes  CheckOther::checkCastIntToCharAndBack
Yes  CheckOther::checkCharVariable
Yes  CheckOther::checkComparePointers
Yes  CheckOther::checkComparisonFunctionIsAlwaysTrueOrFalse
Yes  CheckOther::checkConstPointer
No   CheckOther::checkDuplicateBranch                          require:style,inconclusive
Yes  CheckOther::checkDuplicateExpression
Yes  CheckOther::checkEvaluationOrder
Yes  CheckOther::checkFuncArgNamesDifferent
No   CheckOther::checkIncompleteArrayFill                      require:warning,portability,inconclusive
Yes  CheckOther::checkIncompleteStatement
No   CheckOther::checkInterlockedDecrement                     require:windows-platform
Yes  CheckOther::checkInvalidFree
Yes  CheckOther::checkKnownArgument
Yes  CheckOther::checkKnownPointerToBool
No   CheckOther::checkMisusedScopedObject                      require:style,c++
Yes  CheckOther::checkModuloOfOne
Yes  CheckOther::checkNanInArithmeticExpression
Yes  CheckOther::checkNegativeBitwiseShift
Yes  CheckOther::checkOverlappingWrite
No   CheckOther::checkPassByReference                          require:performance,c++
Yes  CheckOther::checkRedundantAssignment
No   CheckOther::checkRedundantCopy                            require:c++,performance,inconclusive
Yes  CheckOther::checkRedundantPointerOp
Yes  CheckOther::checkShadowVariables
Yes  CheckOther::checkSignOfUnsignedVariable
No   CheckOther::checkSuspiciousCaseInSwitch                   require:warning,inconclusive
No   CheckOther::checkSuspiciousSemicolon                      require:warning,inconclusive
Yes  CheckOther::checkUnreachableCode
Yes  CheckOther::checkUnusedLabel
Yes  CheckOther::checkVarFuncNullUB
Yes  CheckOther::checkVariableScope
Yes  CheckOther::checkZeroDivision
Yes  CheckOther::clarifyCalculation
Yes  CheckOther::clarifyStatement
Yes  CheckOther::invalidPointerCast
Yes  CheckOther::redundantBitwiseOperationInSwitch
No   CheckOther::warningOldStylePointerCast                    require:style,c++
No   CheckPostfixOperator::postfixOperator                     require:performance
Yes  CheckSizeof::checkSizeofForArrayParameter
Yes  CheckSizeof::checkSizeofForNumericParameter
Yes  CheckSizeof::checkSizeofForPointerSize
Yes  CheckSizeof::sizeofCalculation
Yes  CheckSizeof::sizeofFunction
Yes  CheckSizeof::sizeofVoid
Yes  CheckSizeof::sizeofsizeof
No   CheckSizeof::suspiciousSizeofCalculation                  require:warning,inconclusive
No   CheckStl::checkDereferenceInvalidIterator                 require:warning
No   CheckStl::checkDereferenceInvalidIterator2
No   CheckStl::checkFindInsert                                 require:performance
No   CheckStl::checkMutexes                                    require:warning
No   CheckStl::erase
No   CheckStl::if_find                                         require:warning,performance
No   CheckStl::invalidContainer
No   CheckStl::iterators
No   CheckStl::knownEmptyContainer                             require:style
No   CheckStl::misMatchingContainerIterator
No   CheckStl::misMatchingContainers
No   CheckStl::missingComparison                               require:warning
No   CheckStl::negativeIndex
No   CheckStl::outOfBounds
No   CheckStl::outOfBoundsIndexExpression
No   CheckStl::redundantCondition                              require:style
No   CheckStl::size                                            require:performance,c++03
No   CheckStl::stlBoundaries
No   CheckStl::stlOutOfBounds
No   CheckStl::string_c_str
No   CheckStl::useStlAlgorithm                                 require:style
No   CheckStl::uselessCalls                                    require:performance,warning
Yes  CheckString::checkAlwaysTrueOrFalseStringCompare
Yes  CheckString::checkIncorrectStringCompare
Yes  CheckString::checkSuspiciousStringCompare
Yes  CheckString::overlappingStrcmp
Yes  CheckString::sprintfOverlappingData
Yes  CheckString::strPlusChar
Yes  CheckString::stringLiteralWrite
Yes  CheckType::checkFloatToIntegerOverflow
Yes  CheckType::checkIntegerOverflow
Yes  CheckType::checkLongCast
Yes  CheckType::checkSignConversion
Yes  CheckType::checkTooBigBitwiseShift
Yes  CheckUninitVar::check
Yes  CheckUninitVar::valueFlowUninit
Yes  CheckUnusedFunctions::analyseWholeProgram
Yes  CheckUnusedVar::checkFunctionVariableUsage
Yes  CheckUnusedVar::checkStructMemberUsage
Yes  CheckVaarg::va_list_usage
Yes  CheckVaarg::va_start_argument
#include <stdio.h>
#include <stdlib.h>

void input_size(int *n_size_row, int *n_size_col, int *flag);
void pointer_allocated(double **pointer_el, double *matrix_num, int n_size_row, int n_size_col);
void input_num(double **pointer_el, int n_size_row, int n_size_col, int *flag);
void output_matrix(double **matrix_num, int n_size_row, int n_size_col);
double determine(double **matrix, int n_size_row);
double **minor(double **matrix, int n_size_row, int row, int col);
double **algebraic_complements(double **matrix, int n_size_row);
double **transpose(double **matrix, int n_size_row);
double **invert_matrix(double **matrix, int n_size_row, int *flag);

int main() {
    int n_size_row, n_size_col, flag = 0;
    input_size(&n_size_row, &n_size_col, &flag);
    if (flag == 0) {
        if (n_size_row != n_size_col) {
            // Матрица не квадратная
            printf("n/a");
            return 0;
        }

        double *matrix = (double *)malloc(n_size_row * n_size_col * sizeof(double));
        double **pointer_el = (double **)malloc(n_size_row * sizeof(double *));
        pointer_allocated(pointer_el, matrix, n_size_row, n_size_col);

        input_num(pointer_el, n_size_row, n_size_col, &flag);

        if (flag == 0) {
            double **inverse = invert_matrix(pointer_el, n_size_row, &flag);
            if (flag == 0) {
                output_matrix(inverse, n_size_row, n_size_col);
            } else {
                printf("n/a");
            }

            free(inverse[0]);
            free(inverse);
        } else {
            printf("n/a");
        }

        free(matrix);
        free(pointer_el);
    } else {
        printf("n/a");
    }
    return 0;
}

void input_size(int *n_size_row, int *n_size_col, int *flag) {
    *flag = 0;
    char c, c1;
    if (scanf("%d%c%d%c", n_size_row, &c, n_size_col, &c1) != 4 || c != ' ' || c1 != '\n' || *n_size_row <= 0 || *n_size_col <= 0) {
        *flag = 1;
    }
}

void pointer_allocated(double **pointer_el, double *matrix_num, int n_size_row, int n_size_col) {
    for (int i = 0; i < n_size_row; i++) {
        pointer_el[i] = matrix_num + i * n_size_col;
    }
}

void input_num(double **pointer_el, int n_size_row, int n_size_col, int *flag) {
    *flag = 0;
    double temp;
    char c;
    for (int i = 0; i < n_size_row; i++) {
        for (int j = 0; j < n_size_col; j++) {
            if (scanf("%lf%c", &temp, &c) == 2 && (c == ' ' || c == '\n')) {
                pointer_el[i][j] = temp;
            } else {
                *flag = 1;
                return;
            }
        }
    }
}

void output_matrix(double **matrix_num, int n_size_row, int n_size_col) {
    for (int i = 0; i < n_size_row; i++) {
        for (int j = 0; j < n_size_col; j++) {
            if (j == n_size_col - 1) {
                printf("%.6f", matrix_num[i][j]);
            } else {
                printf("%.6f ", matrix_num[i][j]);
            }
        }
        if (i != n_size_row - 1) {
            printf("\n");
        }
    }
}

double determine(double **matrix, int n_size_row) {
    if (n_size_row == 1) {
        return matrix[0][0];
    }

    if (n_size_row == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double det = 0;
    for (int i = 0; i < n_size_row; i++) {
        double **minor_matrix = minor(matrix, n_size_row, 0, i);
        double cofactor = (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determine(minor_matrix, n_size_row - 1);
        det += cofactor;

        free(minor_matrix[0]);
        free(minor_matrix);
    }
    return det;
}

double **minor(double **matrix, int n_size_row, int row, int col) {
    double *minor_data = (double *)malloc((n_size_row - 1) * (n_size_row - 1) * sizeof(double));
    double **minor_matrix = (double **)malloc((n_size_row - 1) * sizeof(double *));
    pointer_allocated(minor_matrix, minor_data, n_size_row - 1, n_size_row - 1);

    for (int i = 0, mi = 0; i < n_size_row; i++) {
        if (i == row) continue;
        for (int j = 0, mj = 0; j < n_size_row; j++) {
            if (j == col) continue;
            minor_matrix[mi][mj] = matrix[i][j];
            mj++;
        }
        mi++;
    }
    return minor_matrix;
}

double **algebraic_complements(double **matrix, int n_size_row) {
    double *data = (double *)malloc(n_size_row * n_size_row * sizeof(double));
    double **result = (double **)malloc(n_size_row * sizeof(double *));
    pointer_allocated(result, data, n_size_row, n_size_row);

    for (int i = 0; i < n_size_row; i++) {
        for (int j = 0; j < n_size_row; j++) {
            double **minor_matrix = minor(matrix, n_size_row, i, j);
            result[i][j] = determine(minor_matrix, n_size_row - 1) * ((i + j) % 2 == 0 ? 1 : -1);

            free(minor_matrix[0]);
            free(minor_matrix);
        }
    }
    return result;
}

double **transpose(double **matrix, int n_size_row) {
    double *data = (double *)malloc(n_size_row * n_size_row * sizeof(double));
    double **transposed = (double **)malloc(n_size_row * sizeof(double *));
    pointer_allocated(transposed, data, n_size_row, n_size_row);

    for (int i = 0; i < n_size_row; i++) {
        for (int j = 0; j < n_size_row; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

double **invert_matrix(double **matrix, int n_size_row, int *flag) {
    double det = determine(matrix, n_size_row);
    if (det == 0) {
        *flag = 1;  // Обратной матрицы не существует
        return NULL;
    }

    double **complements = algebraic_complements(matrix, n_size_row);
    double **transposed = transpose(complements, n_size_row);

    double *data = (double *)malloc(n_size_row * n_size_row * sizeof(double));
    double **inverse = (double **)malloc(n_size_row * sizeof(double *));
    pointer_allocated(inverse, data, n_size_row, n_size_row);

    for (int i = 0; i < n_size_row; i++) {
        for (int j = 0; j < n_size_row; j++) {
            inverse[i][j] = transposed[i][j] / det;
        }
    }

    free(complements[0]);
    free(complements);
    free(transposed[0]);
    free(transposed);

    return inverse;
}
